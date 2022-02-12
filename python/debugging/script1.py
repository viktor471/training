
print(__name__)


class MyClass:

    def __init__(self):
        self.a = 3
        self.b = 4
        self.c = 6


def func(var):
    return var > 2


def main():
    a = 3
    c = MyClass()

    print("hello")

    b = 3

    for i in range(10):
        a = i + 1
        b = i - 3
        print(a, b)


if __name__ == "__main__":
    a = 5
    print(1, 2, 3)
    main()
    func(3)
    func(3)
    if True:
        i = 4
        print(i)

    print(i)

