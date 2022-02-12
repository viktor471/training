
list_1 = [1,2,3]
list_2 = [6,7,8]

def func(arg_1: int, arg_2):
    print("arg_1:", arg_1, "arg_2:", arg_2)


for el in zip(list_1, list_2):
        func(*el)

