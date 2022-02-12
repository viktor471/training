import socket
from select import select


class Server:
    _server_socket: socket.socket
    _client_socket: socket.socket
    _buf_size: int
    _tasks: dict
    _to_read: dict
    _to_write: dict

    def __init__(self):
        self._tasks = {}
        self._to_read = {}
        self._to_write = {}

        self._server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._server_socket.bind()
        self._server_socket.listen()

    def accept(self):
        while True:
            yield "read", self.server_socket
            self.client_socket, address = self._server_socket.accept()

            print("connection from", address)
            self.client(self._client_socket)

    def client(self):
        while True:

            yield "read", self._client_socket
            request = self.client_socket.recv(4096)

            if not request:
                self._client_socket.close()
                break
            else:
                yield "write", self.client_socket
                response = ("answer" + request.decode()).encode()
                self._client_socket.send(response)

    def event_loop(self):

        while any(tasks, to_read, to_write)