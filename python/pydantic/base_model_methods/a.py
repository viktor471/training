from pydantic import BaseModel

class A(BaseModel):
    a: int
    b: int

a = A(a = 3, b = 4)

b = A(a = 5, b = 7)
