
class OriginalClass:
    member_1: str
    member_2: int

    def method_1(self):
        print("method_1")

    # конструктор параметр self нужен в каждом методе класса, для того, чтобы добраться
    # до членов этого класса. В конструкторе создается только member_1. Для member_2 насколько
    # я понимаю даже ссылка не создается на объект в памяти, так как никакого объекта в памяти для member_2
    # нет, поэтому и члена класса member_2 пока что не существует
    def __init__(self):
        print("Сработал конструктор")
        self.member_1 = ""


# создание экземпляра класса OriginalClass
my_object = OriginalClass()

# выводим список членов my_object. Обрати внимание,
# что здесь нет member_2, так как он не был создан в конструкторе
members = dir(my_object)

for member in members:
    print("\t", member)


def some_func(self: OriginalClass):
    print(self.member_1)
    print("new method of OriginalClass")


print("выведет какой тип у объекта функция:", type(some_func))

my_object.new_method = some_func

my_object.new_method()

print("\n члены класса после добавления нового метода")
for member in dir(my_object):
    print("\t", member)

print("\n просто посмотрим есть ли такой метод в созданном объекте")
if "new_method" in dir(my_object):
    print("\tТакой метод есть")

print("\n выведем есть ли такой метод в исходном классе")
if "new_method" in dir(OriginalClass):
    print("\tВ исходном классе тоже есть")
else:
    print("\tВ исходном классе нет метода")

# удалим метод из объекта
del my_object.new_method

print("После удаления метода из объекта")
if "new_method" in dir(my_object):
    print("\tесть после удаления")
else:
    print("\tПосле удаления метод исчез")

