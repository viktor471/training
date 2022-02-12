#! /usr/bin/env python

from http.server import SimpleHTTPRequestHandler, HTTPServer

class HttpRequestHandler(SimpleHTTPRequestHandler):
    def do_get(self):
        root_dir = "."
        try:
            if self.path.endswith('.html'):
                file = open(root_dir + self.path)

                # send code 200 response
                self.send_response(200)

                # send header first
                self.send_header("Content-type", "text-html")
                self.end_headers()

                # send file content to client
                self.wfile.write(file.read())
                file.close()
                return

        except IOError:
            self.send_error(404, "file not found")

class HttpServer(HTTPServer):

    def __init__(self, address: str, port: int):
        super().__init__((address, port), HttpRequestHandler)

    def run(self):
        print("http server is running")
        self.serve_forever()


def main():
    server = HttpServer("127.0.0.1", 5009)
    server.run()


if __name__ == "__main__":
    main()
