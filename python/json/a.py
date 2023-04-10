import json

name = "rtb_banner.json"
with open(name, "r+") as file:
    json_ = json.load(file)
    with open(f"{name.removesuffix('.json')}_.json", "w") as file:
        json.dump(obj = json_, fp = file, indent = 4)
