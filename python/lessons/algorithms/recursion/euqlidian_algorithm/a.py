
def euclidian(a: int, b: int):
    if a < b:
        return euclidian(b, a)
    elif a % b == 0:
        return b
    else:
        return euclidian(a - b, b)

print(euclidian(19, 7))
