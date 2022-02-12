import socket

server = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
server.bind( ("127.0.0.1", 28650) )
server.listen()

while True:
        user_socket, address = server.accept()
        user_socket.send("connected".encode("utf-8"))
        data = user_socket.recv(2000)
        response = "answer: " + data.decode()
        user_socket.send(response.encode())

if __name__ == "__main__":
        pass
