from typing import Sequence

import copy

def selection_sorting(arr: Sequence) -> list:
    arr = copy.copy(arr)

    sorted_ = []

    def sort(arr: list):
        if not arr:
            return sorted_

        min_el = arr[0]

        last_i = 0

        for i, element in enumerate(arr):
            if element < min_el:
                min_el = element
                last_i = i

        sorted_.append(min_el)

        arr.pop(last_i)

        return sort(arr)

    return sort(arr)

def bubble_sort(arr: Sequence) -> list:
    arr = copy.copy(arr)
    for i in range(len(arr)):
        for k in range(len(arr) - i - 1):
            if arr[k + 1] < arr[k]:
                arr[k], arr[k + 1] = arr[k + 1], arr[k]
    return arr


def binary_search(arr: Sequence, element: float | int):
    arr = copy.copy(arr)
    print(f"{arr = }")

    mid = len(arr) // 2
    print(f"{mid = }")
    print(f"{arr[mid] = }")
    if arr[mid] == element:
        return element
    elif arr[mid] < element:
        return binary_search(arr[mid:], element)
    elif arr[mid] > element:
        return binary_search(arr[:mid], element)

numbers = list(int(number) for number in input("enter several numbers: ").split())
element = int(input("enter element for search: "))

for i, number in enumerate(numbers):
    print(f"i: {number}")

print(selection_sorting(numbers))
# print(bubble_sort(numbers))
# sorted = bubble_sort(numbers)
# print(f"{binary_search(sorted, element) = }")
