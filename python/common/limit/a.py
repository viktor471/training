from sympy import *
x = symbols('x')
#f = sin(x)/x
#f = 1/(x)
#f = (x)**(1/2)
f = ((x + 2/3)**(1/2))/x
y = limit(f,x,-oo, '-')
print(y)
