
class MyClass:
    _a: int
    _b: int

    def __call__(self, c, d):
        print("I can call object like a function with parameters")
        print(c+self._a, d + self._b)

    def __init__(self, a, b):
        self._a = a
        self._b = b

        print(self._a, self._b)


my_object = MyClass(2, 3)

my_object(5, 6)


def func():
    print("func first declaration")


func()


def func():
    print("func second declaration")


func()
