import types


def decorator(func_for_decoration: types.FunctionType):
    def wrapper(*args, **kwargs):
        print("before call function:", func_for_decoration.__name__)
        result = func_for_decoration(args, kwargs)
        print("after call function:", func_for_decoration.__name__)
        return result
    return wrapper


@decorator
def print_vars(*args, **kwargs):
    for arg in args:
        # print("arg_{}".format(i), arg)
        print(arg)

    for key, value in kwargs.items():
        print("key:", key, "value:", value)

    return 3


print(print_vars([1, 2, 3], {"h": "b"}))

def func():
    pass

help(func)
