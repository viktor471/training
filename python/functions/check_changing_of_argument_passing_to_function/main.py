def func(a):
    a = 33


b = "hello"


def func(a):
    a = "bye"


func(b)

print(b)

l = [b]


def func(l:list):
    l[0] = "bye"


print(b)