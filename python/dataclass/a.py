from dataclasses import dataclass
from enum import IntEnum

class A(IntEnum):
    a: int = 1
    b: int = 3
    c: int = 4


for i in A:
    print(i.value)