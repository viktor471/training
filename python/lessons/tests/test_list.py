import pytest

from ..structures.doubly_linked_list.a import List


class TestListBaseOperations:
    def test_list_append(self):
        my_list = List()

        assert my_list.size == 0

        my_list.append(3)

        assert my_list.size == 1

        assert my_list.head.data == 3

        my_list.append(4)

        assert my_list.size == 2

        assert my_list.head.data == 3
        assert my_list.head.next.data == 4

    def test_list_chained_append(self):
        my_list = List()
        my_list.append(1).append(2).append(3).append(4)

        assert my_list[1].data == 2

        my_list.pop(1)

        assert my_list[1].data == 3

    def test_list_pop(self):
        my_list = List()

        with pytest.raises(AssertionError):
            my_list.pop()

        my_list.append(3)

        assert my_list.size == 1

        my_list.pop()

        assert my_list.size == 0

        my_list.append(4).append(6).append(7)

        assert my_list.size == 3

        assert my_list.pop(1).data == 6

        assert my_list.size == 2

        assert my_list.head.data == 4

        assert my_list.head.next.data == 7

    def test_list_getitem(self):
        my_list = List([1, 2, 3, 4])

        assert my_list[1].data == 2

        my_list.pop(1)

        assert my_list[1].data == 3

    def test_list_setitem(self):
        data = [1, 2, 3, 4]
        my_list = List(data)

        data[1] = 8
        my_list[1] = 8

        for el_1, el_2 in zip(my_list, data, strict=True):
            assert el_1 == el_2

    def test_list_node_eq(self):
        my_list = List([1, 2, 3, 4])
        node = my_list[1]

        assert my_list[1] == node
        assert my_list[1].data == node.data

    def test_list_insert(self):
        my_list = List([1, 2, 3, 4])

        my_list.insert(0, 99)

        assert my_list[0] == 99
        assert my_list[1] == 1

        my_list.insert(1, 88)

        assert my_list[0] == 99
        assert my_list[1] == 88
        assert my_list[2] == 1

    def test_list_insert_at_empty_list(self):
        my_list = List()
        my_list.insert(0, 8)

    def test_list_setitem_empty_list(self):
        my_list = List()
        my_list[0] = 3
        assert my_list[0] == 3

        my_list[1] = 4

        assert my_list[1] == 4

    @pytest.mark.current
    def test_list_iter(self):
        my_list = List([1, 2, 3, 4])

        for el_1, el_2 in zip(my_list, [1, 2, 3, 4], strict=True):
            assert el_1.data == el_2


@pytest.fixture
def prepare_list_and_data():
    fv = fixture_vars = dict()

    fv["data"] = [1, 2, 3, 4]
    fv["reversed_data"] = reversed(fv["data"])
    fv["reversed_iterator"] = iter(fv["reversed_data"])
    fv["iterator"] = iter(fv["data"])
    fv["list"] = List(fv["data"])

    return fixture_vars


class TestListNodes:
    def test_list_nodes_next(self, prepare_list_and_data):
        fv = prepare_list_and_data
        current = fv["list"].head
        iterator = fv["iterator"]

        while current is not None:
            assert current.data == next(iterator)
            current = current.next

    def test_list_nodes_prev(self, prepare_list_and_data):
        fv = prepare_list_and_data
        current = fv["list"].tail
        reversed_iterator = fv["reversed_iterator"]

        while current is not None:
            assert current.data == next(reversed_iterator)
            current = current.prev

    def test_list_nodes_append_next(self):
        my_list = List()
        my_list.append(3)
        my_list.append(4)

        iterator = iter([3, 4])

        current = my_list.head

        while current is not None:
            assert current.data == next(iterator)
            current = current.next

    @pytest.mark.current
    def test_list_nodes_append_prev(self):
        my_list = List()
        my_list.append(3)
        my_list.append(4)

        iterator = iter([4, 3])

        current = my_list.tail

        while current is not None:
            assert current.data == next(iterator)
            current = current.prev

    def test_list_chained_append_next(self):
        my_list = List()
        my_list.append(1).append(2).append(3).append(4)

        data = [1, 2, 3, 4]

        iterator = iter(data)

        current = my_list.head

        while current is not None:
            assert current.data == next(iterator)
            current = current.next

    def test_list_chained_append_prev(self):
        my_list = List()
        my_list.append(1).append(2).append(3).append(4)

        data = [1, 2, 3, 4]

        iterator = iter(reversed(data))

        current = my_list.tail

        while current is not None:
            assert current.data == next(iterator)
            current = current.prev

    def test_list_pop_next(self):
        data = [1, 2, 3, 4]
        my_list = List(data)

        my_list.pop(1)
        my_list.insert(2, 8)
        data.pop(1)
        data.insert(2, 8)

        iterator = iter(data)

        current = my_list.head

        while current is not None:
            assert current.data == next(iterator)
            current = current.next

    def test_list_pop_prev(self):
        data = [1, 2, 3, 4]
        my_list = List(data)

        my_list.pop(1)
        my_list.insert(2, 8)
        data.pop(1)
        data.insert(2, 8)

        iterator = iter(reversed(data))

        current = my_list.tail

        while current is not None:
            assert current.data == next(iterator)
            current = current.prev

    def test_list_setitem_next(self):
        data = [1, 2, 3, 4]
        my_list = List(data)

        data[1] = 8
        my_list[1] = 8

        iterator = iter(data)
        current = my_list.head

        while current is not None:
            assert current.data == next(iterator)
            current = current.next

    def test_list_setitem_prev(self):
        data = [1, 2, 3, 4]
        my_list = List(data)

        data[1] = 8
        my_list[1] = 8

        iterator = iter(reversed(data))
        current = my_list.tail

        while current is not None:
            assert current.data == next(iterator)
            current = current.prev
