import socket
from select import select


class Server:
    _server_socket: socket.socket
    _client_sockets: list
    _client_addresses: dict
    _buf_size: int
    _requests: dict
    _for_read: list
    _for_send: list
    _ready_to_read: list
    _ready_to_write: list

    def __init__(self, ip: str, port: int, buf_size=4096):
        self._client_sockets = []
        self._client_addresses = {}
        self._requests = {}
        self._for_read = []
        self._for_send = []
        self._ready_to_read = []
        self._ready_to_write = []

        self._server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        end_point = (ip, port)

        self._server_socket.bind(end_point)
        self._server_socket.listen()
        self._for_read.append(self._server_socket)
        self._buf_size = buf_size

    def accept(self):
        client_socket, client_address = self._server_socket.accept()
        self._client_addresses[client_socket] = client_address
        self._for_read.append(client_socket)
        self._for_send.append(client_socket)
        self._client_sockets.append(client_socket)

        print("connection from:", client_address)

    @staticmethod
    def send(sock: socket.socket, string: str):
        sock.send(string.encode())

    def echo(self, sock: socket.socket):
        request_string = self._requests[sock].decode()
        print("received:", request_string)
        self.send(sock, "answer:" + request_string + "\n")
        self._requests.pop(sock)

    def recv(self, sock):
        self._requests[sock] = sock.recv(self._buf_size)

    def run(self):
        while True:
            self._ready_to_read, self._ready_to_write, _ = select(self._for_read, self._for_send, [])
            for sock in self._ready_to_read:
                if sock is self._server_socket:
                    self.accept()
                elif sock in self._client_sockets:
                    self.recv(sock)

            for sock in self._ready_to_write:
                if sock in self._requests:
                    self.echo(sock)


def main():
    server = Server("localhost", 5003)
    server.run()


if __name__ == "__main__":
    main()

