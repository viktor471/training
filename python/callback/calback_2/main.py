import numpy as np


def more(a, b):
    return a > b


def less(a, b):
    return a < b


def sort(my_list, comp):
    for k in range(0, len(my_list) - 1):
        for i in range(0, len(my_list) - 1):
            if comp(my_list[i], my_list[i+1]):
                swap = my_list[i]
                my_list[i] = my_list[i+1]
                my_list[i+1] = swap


ex_list = [8, 3, 9, 5, 4]

sort(ex_list, less)

print(ex_list)


