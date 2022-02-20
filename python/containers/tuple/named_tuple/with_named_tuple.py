#! /usr/bin/env python

from collections import namedtuple
import sys

def get_target(argv: list):
    Container = namedtuple("Container", ["address", "port"])
    return Container(*argv[1:])


def main():
    container = get_target(sys.argv)

    print("address:", container.address)
    print("port:   ", container.port )


if __name__ == "__main__":
    main()

