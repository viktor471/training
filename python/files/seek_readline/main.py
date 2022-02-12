
f = open("file", "w")

f.write("hello \n")
f.write("my \n")
f.write("friend \n")

f = open("file", "r")

print(f.readline(), end='')
print(f.readline(), end='')

f.seek(0)

a = f.read()
print(type(a))
print("=======================")
print(a)

f.seek(0)

for line in f:
    # for char in line.strip():
    for char in line:
        print(char, end=" ")

f.seek(0)

print("================================")
my_list = open("file", "r").readlines()
print(my_list)

