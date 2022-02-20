
def overloaded_func_1(strings: list[str], sep="-"):
    separated_str = sep.join(strings)
    print(separated_str)


def overloaded_func_2(arg1, arg2):
    a = isinstance(arg1, int)
    b = isinstance(arg2, int)

    if a and b:
        return arg1 + arg2

    a = isinstance(arg1, str)
    b = isinstance(arg2, str)

    if a and b:
        return str(arg1).upper() + " " + str(arg2).upper()


def overloaded_func_3(*args):
    for arg in args:
        print(arg, end=" ")
    print()


if __name__ == '__main__':
    overloaded_func_1(["hello", "my", "friend"])
    overloaded_func_1(["hello", "my", "friend"], " ")

    a = overloaded_func_2("hello", "world")
    print(a)

    b = overloaded_func_2(2, 3)
    print(b)

    overloaded_func_3(2, 3, 4, 5, 5)
