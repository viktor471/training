import os

def read_file(file):
    print("file:", file)
    file = open(file)
    return file.read()

print()
print("content of file:")
print(type(read_file("file_for_reading")))
print()
print(read_file("file_for_reading"))
