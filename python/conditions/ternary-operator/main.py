def func(flag: bool) -> int:
    var = 55 if not flag else 99
    return var

def func_2(flag: bool) -> None:
    (print("flag is true")) if flag else print("flag is false")

def main():
    var = func(True)
    print(var)

    var = func(False)
    print(var)

    func_2(True)
    func_2(False)

    
def func():
    print("hello")



if __name__ == "__main__":
    main()
