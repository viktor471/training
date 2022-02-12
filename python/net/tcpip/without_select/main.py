import socket


class Server:
    _server_socket: socket.socket
    _client_socket: socket.socket
    _client_address: str
    _buf_size: int
    _request: bytes

    def __init__(self, ip: str, port: int, buf_size=4096):
        self._server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        end_point = (ip, port)

        self._server_socket.bind(end_point)
        self._server_socket.listen()
        self._buf_size = buf_size

    def accept(self):
        self._client_socket, self._client_address = self._server_socket.accept()
        print("connection from:", self._client_address)

    def send(self, string: str):
        self._client_socket.send(string.encode())

    def echo(self):
        request_string = self._request.decode()
        print("received:", request_string)
        self.send("answer:" + request_string + "\n")

    def recv(self):
        self._request = self._client_socket.recv(self._buf_size)

    def run(self):
        while True:
            print("Before accept")
            self.accept()

            while True:
                self.recv()

                if not self._request:
                    break
                else:
                    self.echo()


def main():
    server = Server("localhost", 5001)
    server.run()


if __name__ == "__main__":
    main()

