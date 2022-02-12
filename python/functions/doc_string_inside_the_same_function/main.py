
def func():
    """this is docstring"""
    print(func.__doc__)
    # print(func.__code__)
    func.variable += 1
    print(func.variable)


func.variable = 1

func()
func()
func()