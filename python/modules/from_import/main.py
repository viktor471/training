from print_phrase import print_hello as hello
from print_phrase import MyClass as SomeOtherName

hello()

ex = SomeOtherName('bye')

ex.print_phrase()

some_other_name = hello

some_other_name()

AnotherName = SomeOtherName

ex_2 = AnotherName("world")

ex_2.print_phrase()

print(hello.__name__)

help(AnotherName)

if __name__ == "__main__":
    pass