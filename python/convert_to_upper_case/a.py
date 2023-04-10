
file_name = "ifas.txt"

with open(file_name) as file:
    with open(f"{file_name}_", "w") as file_:
            file_.writelines(line.upper() for line in file.readlines())