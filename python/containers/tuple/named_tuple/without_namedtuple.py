#! /usr/bin/python

import sys

class Container:
    def __init__(self, address: str, port: int):
        self.address = address
        self.port = port

def main():
    container = Container(*sys.argv[1:])
    print("port:   ", container.port)
    print("address:", container.address)


if __name__ == "__main__":
    main()
