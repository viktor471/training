import socket
import selectors


class Server:
    _selector: selectors.DefaultSelector
    _server_socket: socket.socket
    _buf_size: int
    _requests: dict

    class EventHandler:
        NonEvent = 3

        class Event:
            def __init__(self, func, args: list):
                self.func = func
                self.args = args

            def __call__(self):
                self.func(*self.args)

        _events = {}

        def __init__(self, func=None, event=NonEvent, args=[]):
            self._events = {}

            if func is not None:
                self._events[event] = self.Event(func, args)

        def append(self, func, event=NonEvent, args=[]):
            self._events[event] = self.Event(func, args)

        def __call__(self, event: int):
            if self.NonEvent not in self._events:
                self._events[event]()
            else:
                self._events[self.NonEvent]()

    def __init__(self, ip: str, port: int, buf_size=4096):
        self._requests = {}
        self._buf_size = buf_size

        self._selector = selectors.DefaultSelector()
        self._server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        end_point = (ip, port)

        self._server_socket.bind(end_point)
        self._server_socket.listen()

        server_handler = self.EventHandler(self.accept)
        self._selector.register(self._server_socket, selectors.EVENT_READ, server_handler)

    def accept(self):
        client_socket, client_address = self._server_socket.accept()
        print("connection from:", client_address)
        client_handler = self.EventHandler()
        client_handler.append(self.recv, selectors.EVENT_READ, [client_socket])
        client_handler.append(self.echo, selectors.EVENT_WRITE, [client_socket])
        self._selector.register(client_socket, selectors.EVENT_READ | selectors.EVENT_WRITE, client_handler)

    @staticmethod
    def send(sock: socket.socket, string: str):
        sock.send(string.encode())

    def echo(self, sock: socket.socket):
        if self._requests:
            request_string = self._requests[sock].decode()
            print("received:", request_string)
            self.send(sock, "answer:" + request_string + "\n")
            self._requests.pop(sock)

    def recv(self, sock: socket.socket):
        request = sock.recv(self._buf_size)
        if request:
            self._requests[sock] = request
        else:
            self._selector.unregister(sock)
            sock.close()

    def run(self):
        while True:
            selector_key = self._selector.select()
            for key, event in selector_key:
                if event is selectors.EVENT_READ | selectors.EVENT_WRITE:
                    key.data(selectors.EVENT_READ)
                    key.data(selectors.EVENT_WRITE)
                else:
                    key.data(event)


def main():
    server = Server("localhost", 5001)
    server.run()


if __name__ == "__main__":
    print(print.__name__)

    a = print
    a("hello")

    main()

