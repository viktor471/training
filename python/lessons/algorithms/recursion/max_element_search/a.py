from typing import Any, Sequence

def search_max_element(arr: Sequence) -> Any:
    max_el = arr[0]
    def search(arr: Sequence):
        nonlocal max_el

        if len(arr) == 1:
            if max_el < arr[0]:
                max_el = arr[0]
            return max_el

        if max_el < arr[0]:
            max_el = arr[0]

        return search(arr[1:])

    return search(arr)

numbers = [int(number) for number in input("Enter several numbers: ").split()]

print(search_max_element(numbers))
