#! /usr/bin/env python
import socket
import sys
import pickle 

#msg_from_client = "hello udp server"

class MyClass:
    def __init__(self, values: dict):
        for key, value in values.items():
            setattr(self, key, value)

my_class = MyClass({"a": 2, "b": 3})

bytes_to_send = pickle.dumps(my_class)

#bytes_to_send = str.encode(msg_from_client)
server_address_port = (sys.argv[1], int(sys.argv[2]))
buffer_size = 1024

udp_client_socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

udp_client_socket.sendto(bytes_to_send, server_address_port)

msg_from_server = udp_client_socket.recvfrom(buffer_size)

msg = "Message from server {}".format(msg_from_server[0])

print(msg)
