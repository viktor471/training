import typing


def type_hinting(a: int, b: int = 4.0) -> None:
    return a + b


def print_type_hinting():
    print(type_hinting(4))


def main():
    print_type_hinting()
    a: int = 3
    print(f"{a} {a}")
    a: typing.Union[int, float] = "hello"
    print(f" {a}")


if __name__ == '__main__':
    main()
