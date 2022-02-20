

def my_sum(arg1, arg2):
    return arg1 + arg2


def multiply_on3(arg1, arg2, arg3):
    return arg1*3, arg2*3, arg3*3


def main_func(callback):
    def inner_func(args):
        return callback(*args)
    return inner_func


returned_func_1 = main_func(my_sum)
returned_func_2 = main_func(multiply_on3)

print(returned_func_1([1, 2]))
print(returned_func_2([1, 2, 3]))


def multiply_on3(arg):
    return arg*3


def minus_2(arg):
    return arg - 2


def main_func(arg, callback):
    def inner_func():
        print(callback(arg))
    return inner_func


returned_func_1 = main_func(3, minus_2)
returned_func_1()

returned_func_2 = main_func(3, multiply_on3)
returned_func_2()
