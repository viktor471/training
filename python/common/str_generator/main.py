import random_date as rnd_date
import datetime as dt
import typing as tp

start_date = dt.datetime(1900, 1, 1)
end_date = dt.datetime(2022, 1, 1)


def string_generator(**args):
    start_date_ = args.values()[0]
    end_date_ = args.values()[1]
    sep = args.values()[2]
    return rnd_date.get_string_with_random_date(start_date_, end_date_, sep)


str_generator = tp.Callable[[...], str]


def caller(generator: str_generator, **args):
    print(generator(args))


def main():
    caller(string_generator, args=[start_date, end_date, "-"])


if __name__ == '__main__':
    main()
