def func_1():
    # global c
    print("func_1")
    def func_2():
        print("func_2")
        global c
        c = 55
    global a
    a = func_2
    a()
    func_2()
    print(c)


b = func_1
b()
b()
print("in main:", c)
print(type(b))

# a()
# func_1()
# func_2()
# a = func_1
# print(a)