
x1, x2, x3 = False, True, False
if __name__ == '__main__':
    pass

print(not x1 or x2 and x3)
print(True or True and False)

x = 5
y = 10

a = y > x * x or y >= 2 * x and x < y
print(a)

a = True
b = False

print("last:", a and b or not a and not b)

