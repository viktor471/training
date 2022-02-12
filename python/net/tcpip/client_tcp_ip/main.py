
import socket

client = socket.socket(
    socket.AF_INET,
    socket.SOCK_STREAM
)

client.connect(
    ("127.0.0.1", 30000 )
)

import math
print(math.pi/2)

while True:
  client.send("hello".encode("utf-8"))
