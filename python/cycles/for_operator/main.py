import math

def main():
    print(make_squares())

    for x in 4, 3, 2:
        print(x ** 2)

    for x in make_squares():
        print(math.sqrt(x))

def make_squares():
    return [a ** 2 for a in (2, 4, 5)]


if __name__ == '__main__':
    main()
