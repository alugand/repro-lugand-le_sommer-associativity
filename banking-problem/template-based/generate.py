import os
import subprocess
import csv
from jinja2 import Environment, FileSystemLoader
import sys

# --- Configuration ---
# Determine directories relative to this script file
SRC_DIR = os.path.dirname(os.path.abspath(__file__)) # Directory containing this script
REPO_ROOT = os.path.abspath(os.path.join(SRC_DIR, '..')) # Project root (one level up)
ANALYZE_DIR = os.path.join(REPO_ROOT, 'analyze')
RESULTS_FILE = os.path.join(ANALYZE_DIR, 'results.csv') # Correct path for results
TEMPLATE_NAME = 'banking-template.cpp.jinja' # Corrected template name
CPP_FILENAME = 'generated_banking_calc.cpp' # Corrected C++ filename
EXE_FILENAME = 'generated_banking_calc' # Corrected executable filename

# --- Define Variants Directly in the Script ---
VARIANTS = [
    {'compil-option': '', 'type': 'float'},
    {'compil-option': '', 'type': 'double'},
    {'compil-option': '', 'type': 'long double'},
    {'compil-option': '-O2 -ffloat-store -fno-fast-math', 'type': 'float'},
    {'compil-option': '-O2 -ffloat-store -fno-fast-math', 'type': 'double'},
    {'compil-option': '-O2 -ffloat-store -fno-fast-math', 'type': 'long double'},
    # Add more variants here if needed
]
# --- End Configuration ---

def run_all_variants():
    """
    Iterates through predefined variants, generates C++ code, compiles, runs, and saves results.
    """
    # Ensure analyze directory exists
    os.makedirs(ANALYZE_DIR, exist_ok=True)

    # --- Load Jinja Template ---
    # Load template from the same directory as this script
    env = Environment(loader=FileSystemLoader(SRC_DIR))
    try:
        template = env.get_template(TEMPLATE_NAME)
    except Exception as e:
        print(f"Error loading template {TEMPLATE_NAME} from {SRC_DIR}: {e}")
        sys.exit(1)

    # --- Initialize Results List ---
    results_list = []

    # --- Iterate Through Variants ---
    if not VARIANTS:
        print("Error: The VARIANTS list is empty.")
        sys.exit(1)
    print(f"Starting experiments for {len(VARIANTS)} variants defined in the script.")

    for i, variant in enumerate(VARIANTS):
        print(f"\n--- Running Variant {i+1}/{len(VARIANTS)} ---")
        compil_option = variant.get('compil-option', '')
        data_type = variant.get('type', 'double')
        print(f"  Type: {data_type}, Options: '{compil_option}'")

        # Define output filename based on variant details for clarity
        # Replace spaces in type for filename compatibility
        safe_type_name = data_type.replace(' ', '_')
        output_txt_filename = f"answer_{safe_type_name}_variant_{i}.txt"
        # Output file will be created in SRC_DIR
        output_txt_filepath = os.path.join(SRC_DIR, output_txt_filename)

        # Prepare context for Jinja template
        context = {
            "type": data_type,
            "output_file": output_txt_filepath, # Pass the path to the C++ code
        }

        # --- Generate C++ Code ---
        generated_code_path = os.path.join(SRC_DIR, CPP_FILENAME)
        try:
            code = template.render(context)
            with open(generated_code_path, "w") as f:
                f.write(code)
        except Exception as e:
            print(f"  Error generating code: {e}")
            results_list.append({
                'compil-option': compil_option,
                'type': data_type,
                'result': f"Error generating code: {e}"
            })
            continue # Skip to next variant

        # --- Compile C++ Code ---
        executable_path = os.path.join(SRC_DIR, EXE_FILENAME)
        compile_command = f"g++ {compil_option.strip()} {generated_code_path} -o {executable_path} -lm" # Added -lm
        print(f"  Compiling: {compile_command}")
        # Run compilation from SRC_DIR
        compile_process = subprocess.run(compile_command, shell=True, capture_output=True, text=True, cwd=SRC_DIR)

        if compile_process.returncode != 0:
            print(f"  Error compiling:")
            print(compile_process.stderr)
            results_list.append({
                'compil-option': compil_option,
                'type': data_type,
                'result': f"Compilation Error: {compile_process.stderr[:100]}" # Store error snippet
            })
            continue # Skip to next variant

        # --- Run Executable ---
        # Command needs to be relative to the cwd (SRC_DIR)
        run_command = f"./{EXE_FILENAME}"
        print(f"  Executing: {run_command}")
        # Run executable from SRC_DIR
        run_process = subprocess.run(run_command, shell=True, capture_output=True, text=True, cwd=SRC_DIR)

        current_result = "Execution Failed" # Default result
        if run_process.returncode != 0:
            print(f"  Error running executable:")
            print(run_process.stderr)
            current_result = f"Runtime Error: {run_process.stderr[:100]}" # Store error snippet
        else:
            # --- Read Result from Output File ---
            try:
                # output_txt_filepath is already the correct path relative to script start
                with open(output_txt_filepath, 'r') as f_result:
                    current_result = f_result.read().strip()
                print(f"  Result read from {output_txt_filename}: {current_result}")
            except FileNotFoundError:
                print(f"  Error: Output file {output_txt_filepath} not found after execution.")
                current_result = "Output file not found"
            except Exception as e:
                print(f"  Error reading output file {output_txt_filepath}: {e}")
                current_result = f"Error reading result file: {e}"

        # --- Append Result to List ---
        results_list.append({
            'compil-option': compil_option,
            'type': data_type,
            'result': current_result
        })

        if os.path.exists(output_txt_filepath):
             os.remove(output_txt_filepath)
             # print(f"    Removed: {output_txt_filepath}")


    # --- Store Results List to CSV ---
    if results_list:
        fieldnames = list(results_list[0].keys()) # Get headers from first result dict
        try:
            # Ensure the directory exists before writing
            os.makedirs(ANALYZE_DIR, exist_ok=True)
            with open(RESULTS_FILE, 'w', newline='') as f_results:
                writer = csv.DictWriter(f_results, fieldnames=fieldnames)
                writer.writeheader()
                writer.writerows(results_list)
            print(f"\nExperiments finished. Results stored in {RESULTS_FILE}")
        except Exception as e:
            print(f"\nError writing results to {RESULTS_FILE}: {e}")
    else:
        print("\nNo results were generated.")


if __name__ == "__main__":
    run_all_variants()

