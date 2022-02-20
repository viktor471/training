
class MyClass:
    a: int
    b: int

    def __init__(self, aa, bb):
        self.a = aa
        self.b = bb


def answer(condition):
    if condition:
        print("yes")
    else:
        print("no")


my_list = []

my_list.append(MyClass(3, 5))

a = MyClass(9, 8)

my_list.append(a)

answer(a in my_list)

answer(a is my_list[1])

my_list.append(MyClass(9, 8))

answer(a is my_list[2])
