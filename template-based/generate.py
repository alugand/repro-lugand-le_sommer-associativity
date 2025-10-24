from jinja2 import Environment, FileSystemLoader
import subprocess
import csv

# Read factors from variant.csv
factors = []
with open('../analyze/variant.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        factors.append({
            "operation1": "(val1 + val2) + val3",
            "operation2": "val1 + (val2 + val3)",
            "repetitions": int(row['nbexp']),
            "output_file": f"answer_{row['type']}_{row['nbexp']}.txt",
            "type": row['type'],
            "option1": row['compil-option']
        })

env = Environment(loader=FileSystemLoader('.'))
template = env.get_template('number_template.cpp.jinja')

results = []
for factor in factors:
    code = template.render(factor)
    filename = "generated_number_check.cpp"
    with open(filename, "w") as f:
        f.write(code)
    print(f"Code généré dans {filename}")
    
    # Compile the C++ code
    compile_process = subprocess.run(f"g++ {factor['option1']} generated_number_check.cpp -o generated_number_check", shell=True, capture_output=True, text=True)
    if compile_process.returncode != 0:
        print(f"Error compiling for factor: {factor}")
        print(compile_process.stderr)
        continue

    # Run the C++ code
    run_process = subprocess.run("./generated_number_check", shell=True, capture_output=True, text=True)
    if run_process.returncode != 0:
        print(f"Error running for factor: {factor}")
        print(run_process.stderr)
        continue
    
    # Read the result from the output file
    try:
        with open(factor['output_file'], 'r') as f_result:
            result = f_result.read().strip()
    except FileNotFoundError:
        result = "File not found"

    results.append({
        'nbexp': factor['repetitions'],
        'compil-option': factor['option1'],
        'type': factor['type'],
        'result': result
    })

# Store results in results.csv
with open('../analyze/results.csv', 'w+', newline='') as f_results:
    fieldnames = ['nbexp', 'compil-option', 'type', 'result']
    writer = csv.DictWriter(f_results, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(results)

print("Experiments finished. Results stored in ../analyze/results.csv")