
def func_with_default_parameters( arg_1 = 3, arg_2 = 4 ) :
    return arg_1 + arg_2

without_parameters = func_with_default_parameters()
with_parameters    = func_with_default_parameters(4, 1)

def main():
    print()
    print( "without parameters:" )
    print( without_parameters    )
    print()
    print( "with parameters:"    )
    print( with_parameters       )
    print()


condition = __name__ == "__main__"


if condition :
    main()

