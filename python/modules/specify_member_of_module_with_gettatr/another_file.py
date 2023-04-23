from pydantic import BaseModel


class A(BaseModel):
    a: int = 3
    b: int = 4
    c: int = 77
