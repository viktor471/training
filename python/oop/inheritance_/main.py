class A:
    a = 4

class B(A):
    b = 5

b = B()

print(b.a, b.b)

class C(int):
    c = 66

print(C().c)

print("AAA".lower())

print( int(-5).__abs__())