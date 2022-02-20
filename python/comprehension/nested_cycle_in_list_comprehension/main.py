import string
import numpy as np


class MyClass:
    inner_dict: dict

    def __init__(self):
        self.inner_dict = {}


def create_new_object() -> MyClass:
    my_object = MyClass()
    for letter in list(string.ascii_lowercase):
        my_object.inner_dict[letter] = list(np.random.randint(10, 99, 2))
    return my_object


list_of_objects = [create_new_object() for i in range(1, 4)]


new_list = [element for my_object in list_of_objects for element in my_object.inner_dict['a'] if 'a' in my_object.inner_dict.keys()]

print()
del list_of_objects[1].inner_dict['a']

new_list = [element for element in
            [inner_dict.values() for inner_dict in
             [my_object.inner_dict for my_object in
              [my_object for my_object in list_of_objects if 'a' in my_object.inner_dict.keys()]]]]

new_list = [element for inner_dict in
            [my_object.inner_dict for my_object in list_of_objects if 'a' in my_object.inner_dict.keys()]
            for inner_list in list(inner_dict.values())
            for element in inner_list]

print(new_list)
