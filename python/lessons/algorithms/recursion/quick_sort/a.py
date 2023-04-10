import time

from typing import Sequence
from enum import Enum


class Pivot(Enum):
    FIRST = "first"
    LAST  = "last"
    MID   = "mid"

def quick_sort(arr: Sequence, pivot_type: Pivot) -> list:
    if len(arr) < 2:
        return arr

    if pivot_type == Pivot.FIRST:
        pivot = arr[0]
    elif pivot_type == Pivot.LAST:
        pivot = arr[len(arr) - 1]
    elif pivot_type == Pivot.MID:
        pivot = arr[len(arr) // 2]

    less = [el for el in arr if el < pivot]
    greater = [el for el in arr if el > pivot]

    return quick_sort(less, pivot_type) + [pivot] + quick_sort(greater, pivot_type)


numbers = [int(number) for number in input("enter several numbers: ").split()]

start = time.perf_counter()
numbers_1 = quick_sort(numbers, Pivot.FIRST)
elapsed_sec_1 = time.perf_counter() - start


start = time.perf_counter()
numbers_2 = quick_sort(numbers, Pivot.MID)
elapsed_sec_2 = time.perf_counter() - start


start = time.perf_counter()
numbers_3 = quick_sort(numbers, Pivot.LAST)
elapsed_sec_3 = time.perf_counter() - start

print(f"first el as pivot. elapsed {elapsed_sec_1} sec")
print(numbers_1)

print(f"mid el as pivot. elapsed {elapsed_sec_2} sec")
print(numbers_2)

print(f"last el as pivot. elapsed {elapsed_sec_3} sec")
print(numbers_3)
