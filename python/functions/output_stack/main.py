import inspect

def func_1():
    # print("func_1")
    print(inspect.stack()[0])
    print(inspect.stack()[1])
    print(inspect.stack()[2])
    print(inspect.stack()[3])
    print("========")
    print(inspect.stack()[0][0])
    print(inspect.stack()[1][0])
    print(inspect.stack()[2][0])
    print(inspect.stack()[3][0])
    print("=====")
    print(inspect.stack()[0][1])
    print(inspect.stack()[1][1])
    print(inspect.stack()[2][1])
    print(inspect.stack()[3][1])
    print("=====")
    print(inspect.stack()[0][2])
    print(inspect.stack()[1][2])
    print(inspect.stack()[2][2])
    print(inspect.stack()[3][2])
    print("=====")
    print(inspect.stack()[0][3])
    print(inspect.stack()[1][3])
    print(inspect.stack()[2][3])
    print(inspect.stack()[3][3])
    print("=====")

def func_2():
    # print("func_2")
    # print(inspect.stack())
    func_1()

def func_3():
    # print("func_3")
    # print(inspect.stack())
    func_2()

func_3()

