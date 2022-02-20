import socket
from select import select

for_read = []
for_write = []
ready_to_read = []
ready_to_write = []

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind(("localhost", 5001))
server_socket.listen()

for_read.append(server_socket)

ready_to_read, ready_to_write, _ = select(for_read, for_write, [])

client_socket: socket.socket

if server_socket in ready_to_read:
    client_socket, address = server_socket.accept()
    for_read.append(client_socket)
    print("receive connection from:", address)

print("before 1 select")
ready_to_read, ready_to_write, _ = select(for_read, for_write, [])

if client_socket in ready_to_read:
    buf = client_socket.recv(4096)
    print(buf.decode())

print("before 2 select")
ready_to_read, ready_to_write, _ = select(for_read, for_write, [])

if client_socket in ready_to_read:
    buf = client_socket.recv(4096)
    print(buf.decode())


