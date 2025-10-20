from jinja2 import Environment, FileSystemLoader
import subprocess

factors = [
    {"operation1": "(val1 + val2) + val3",
     "operation2": "val1 + (val2 + val3)",
     "repetitions": 100000,
     "output_file": "answer_ld.txt",
     "type": "long double",
     "option1": ""},
     

    {"operation1": "(val1 + val2) + val3",
     "operation2": "val1 + (val2 + val3)",
     "repetitions": 100000,
     "output_file": "answer_float.txt",
     "type": "float",
     "option1": "-O2 -ffloat-store -fno-fast-math"}
]

env = Environment(loader=FileSystemLoader('.'))
template = env.get_template('number_template.cpp.jinja')

for factor in factors:
    code = template.render(factor)
    filename = "generated_number_check.cpp"
    with open(filename, "w") as f:
        f.write(code)
    print(f"Code généré dans {filename}")
    subprocess.run(f"g++ {factor['option1']} generated_number_check.cpp -o generated_number_check", shell=True)
    subprocess.run("./generated_number_check", shell=True)
