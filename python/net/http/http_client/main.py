#!/usr/bin/env python

import http
import sys
from collections import namedtuple
from http.client import HTTPConnection as Connection

def get_target():
    Target = namedtuple("Target", ["address", "port"])
    return Target(*sys.argv[1].split(":"))

conn = HTTPConnection(http_server)

class Server:
    def __init__(self, address, port):
        self.connection =

while True:
    Command = namedtuple("Command", ["cmd", "arg"])
    command = Command(input("input command (ex. GET index.html): ").split(" "))

    if command.cmd == 'exit':  # type exit to end it
        break

        # request command to server
    conn.request(command.cmd, command.arg)

    # get response from server
    rsp = conn.getresponse()

    # print server response and data
    print(rsp.status, rsp.reason)
    data_received = rsp.read()
    print(data_received)

conn.close()