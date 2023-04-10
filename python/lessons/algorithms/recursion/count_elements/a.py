from typing import Sequence

def get_len(arr: Sequence):
    if not arr:
        return 1 + get_len(arr[1:])
    else:
        return 0
