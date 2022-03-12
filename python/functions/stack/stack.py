import inspect

print(inspect.stack()[0][3])

def f_1():
    print("f_1:", inspect.stack()[0][3])

def f_2():
    print("f_2:", inspect.stack()[0][3])
    f_1()

def f_3():
    print("f_3:", inspect.stack()[0][3])
    f_2()

f_3()



