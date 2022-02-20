#! /usr/bin/env python
import sys
from http.server import SimpleHTTPRequestHandler, HTTPServer
from my_modules.get_target import Target

class HttpRequestHandler(SimpleHTTPRequestHandler):
    ROOT_DIR = "."
    # def __init__(self, target: tuple):
    #     super(HttpRequestHandler, self).__init__(target)
    #     self.ROOT_DIR = "."

    def get_file(self):
        try:
            return open("index.html")

        except IOError:
            self.send_error(404, "file not found")
            exit(-1)

    def send_page(self):
        file = self.get_file()
        # send file content to client
        self.wfile.write(file.read().encode())
        file.close()

    def do_GET(self):
        # send code 200 response
        self.send_response(200)

        # send header first
        self.send_header("Content-type", "text-html")
        self.end_headers()
        # send page to client
        self.send_page()


class Server(HTTPServer):

    def __init__(self, target: Target):
        super().__init__((target.address, target.port), HttpRequestHandler)

    def run(self):
        print("http server is running")
        self.serve_forever()


def main():
    server = Server(Target(sys.argv))
    server.run()


if __name__ == "__main__":
    main()
