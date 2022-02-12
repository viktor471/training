from collections import namedtuple
import sys

def get_target():
    Target = namedtuple("Target", ["address", "port"])
    return Target(*sys.argv[1].split(":"))


if __name__ == "__main__":
    print(get_target().address, get_target().port)
