
def func(args):
    print(args)

    if args:
        args.pop()
        func(args)



func([1, 2, 3])

