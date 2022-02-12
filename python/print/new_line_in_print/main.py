from typing import List, Union, Any

print([x ** 2 - 1 for x in range(10)])

a = [x ** 2 for x in range(10)]
print(a)

a = [x % 2 for x in range(10)]
print(a)

a: list[Union[int, Any]] = [((-1) ** x) * x for x in range(10)]
print(a)

a = lambda x, y: print(x * y)

a(2, 3)
a = Union[3, "hello"]
print(a)
print(type(a))
