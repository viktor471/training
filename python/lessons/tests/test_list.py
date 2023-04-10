import pytest

from ..structures.list.a import List

class TestList:
    def test_list_append(self):
        my_list = List()

        assert my_list.size() == 0

        my_list.append(data = 3)

        assert my_list.size() == 1

        assert my_list.data == 3

        my_list.append(data = 4)

        assert my_list.size() == 2

        assert my_list.data == 3
        assert my_list.next.data == 4