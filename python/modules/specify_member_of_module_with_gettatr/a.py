import another_file
from pydantic import BaseModel


class TestsBaseModel(BaseModel):
    a: int = 1
    b: int = 2

    def model(self):
        sql_alchemy_model = another_file.__dict__[f"{self.__class__.__name__}"]
        return sql_alchemy_model(**self.dict())


class A(TestsBaseModel):
    pass


a = A(a=99, b=88)
b = a.model()

print(b)
