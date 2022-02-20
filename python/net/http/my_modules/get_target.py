from collections import namedtuple

class Target:

    _UnpackArgv = namedtuple("UnpackArgv", ["address", "port"])

    def __init__(self, argv: list):
        try:
            unpack_argv = self._UnpackArgv(*argv[1].split(":"))
            self.address = unpack_argv.address
            self.port = int(unpack_argv.port)

        except IndexError:
            print("you must specify target. For example: \"127.0.0.1:5009\"")
            exit(-1)
