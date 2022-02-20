#!/usr/bin/env python
import sys
from http.client import HTTPConnection as Connection
from collections import namedtuple
from my_modules.get_target import Target

class Client:
    def __init__(self, target: Target):
        self._address = target.address
        self._port = target.port
        self.open_connection()

    def open_connection(self):
        self.connection = Connection(self._address, self._port)

    @staticmethod
    def get_command():
        Command = namedtuple("Command", ["cmd", "arg"])
        return Command(*input("input command (ex. GET index.html): ").split(" "))

    def execute_command(self):
        command = self.get_command()

        if command.cmd == 'exit':  # type exit to end it
            return

        # request command to server
        self.connection.request(command.cmd, command.arg)

    def get_response(self):
        # get response from server
        rsp = self.connection.getresponse()

        # print server response and data
        print(rsp.status, rsp.reason)
        data_received = rsp.read()
        print(data_received)

    def close_connection(self):
        self.connection.close()

    def run(self):
        self.execute_command()
        self.get_response()


def main():
    client = Client(Target(sys.argv))
    client.run()


if __name__ == "__main__":
    main()



