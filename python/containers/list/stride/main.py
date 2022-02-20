import random as rnd

def main_1():
    mylist = []

    x: int
    for x in range(11):
        print(x)
        mylist.append(rnd.randint(0, 100))
    print(len(()))
    print(mylist)
    print("[3:8:2]", mylist[3:8:2])


def main_2():
    list_of_lists = []
    for x in range(3):
        in_list = []
        for y in range(4):
            in_list.append(rnd.randint(1, 10))
        list_of_lists.append(in_list)
    print(list_of_lists)


def func_1():
    print("im func_1")


def func_2():
    print("im func_2")


def func_3():
    func_list = [func_1, func_2]
    for x in func_list:
        x()

    print(func_list)
    print(tuple(func_list))
    print(type(tuple(func_list)))


if __name__ == '__main__':
    func_3()
