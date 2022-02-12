import typing
import typing as tp


def callback_1(a: float):
    print("in callback_1:", a)


def callback_2(a: int):
    print("in callback_2:", a)


def caller(func: typing.Callable[tp.Union[int,float], None], a):
    func(a)


def main():
    caller(callback_1, 3.4)


if __name__ == '__main__':
    main()
