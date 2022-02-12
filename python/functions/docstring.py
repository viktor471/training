
class my_class:
    """ descrription
    """


def func(arg_1:str, arg_2: int) -> str:
    """sum two strings

    Args:
        arg_1 (str): this is arg_1
        arg_2 (int): this is arg_2

    Returns:
        str: this is returned string
    """


print(func.__doc__)
print(my_class.__doc__)

if __name__ == "__main__":
    pass
