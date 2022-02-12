def print_b() -> None:
    print(Test.b)


class Test:
    def __init__(self):
        print("Test ctor without args.")
        _a = 55
        _b = 66

        print(f"Test ctor without args. Args: _a {_a}, _b {_b}")

    def __init__(self, a, b=88):
        print("Test ctor with args")
        _a = a, _b = b

    _a = 33
    _b = 44

    def print_a(self) -> None:
        print(self._a)
        # print(a)

    def print_smth(self, value):
        print(f"\"print smth\" with one arg: {value}")
        print(value)

    def print_smth(self, value_1, value_2):
        print(f"\"print smth\" with two args: {value_1}, {value_2}")


def main():
    g = Test()
    g.print_a()
    g = Test(3)
    print_b()
    g.print_smth(44)
    g.print_smth(44,66)
if __name__ == "__main__":
    main()
