import logging
from typing import Any, Optional, Sequence


class List:
    class Node:
        def __init__(self,
                     data: Any,
                     next_: Optional["List.Node"] = None,
                     prev_: Optional["List.Node"] = None):
            self._data = data
            self._next = next_
            self._prev = prev_

        @property
        def next(self) -> "List.Node":
            return self._next

        @next.setter
        def next(self, next: "List.Node") -> "List.Node":
            assert isinstance(next, type(self)) or next is None
            self._next = next
        
        @property
        def prev(self) -> "List.Node":
            return self._prev

        @prev.setter
        def prev(self, prev: "List.Node") -> "List.Node":
            assert isinstance(prev, type(self)) or prev is None
            self._prev = prev

        @property
        def data(self) -> Any:
            return self._data

        def __eq__(self, another: "List.Node"):
            match another:
                case List.Node():
                    return self.data == another.data
                case _:
                    return self.data == another

    def __init__(self, seq: Sequence | None = None):
        self._head: Optional[self.Node] = None
        self._size: int = 0
        self._tail: Optional[self.Node] = None

        if seq is not None:
            for el in seq:
                self.append(el)

    class Iterator:
        def __init__(self, start_node: "List.Node"):
            assert isinstance(start_node, List.Node)
            self._current_node = start_node

        def __next__(self):
            if self._current_node is None:
                raise StopIteration
            else:
                current_node = self._current_node
                self._current_node = self._current_node.next
                return current_node

        def __iter__(self):
            return self

    def __bool__(self):
        return bool(self.size)

    def __iter__(self):
        return List.Iterator(self.head)

    @property
    def size(self) -> int:
        return self._size

    @property
    def tail(self) -> "Node":
        return self._tail

    def append(self, data: Any) -> "List":
        if self:
            self.tail.next = self.Node(data=data, prev_=self.tail)
            self._tail = self.tail.next
        else:
            self._head = self.Node(data=data)
            self._tail = self.head

        self._size += 1

        return self

    @property
    def head(self) -> "Node":
        return self._head

    def prepend(self, data) -> "List":
        head = self.head
        self._head = self.Node(data=data)
        self.head.next = head
        self.head.next.prev = self.head
        self._size += 1

        return self

    def __getitem__(self, index: int) -> "Node":
        current = self.head
        i = 0
        logging.info(f"{self.size=} {i=}")
        while i < self.size:
            logging.info(f"{index=} {i=}")
            if i == index:
                break
            i += 1
            current = current.next
        else:
            raise AssertionError("index out of range")

        return current

    def _insert(self, index, data) -> "Node":
        if index == 0:
            inserted = self.Node(data=data, next_=self._head)
            self._head = inserted
        else:
            prev = self[index - 1]
            inserted = self.Node(data=data, next_=prev.next)
            prev.next = inserted
            prev.next.next.prev = prev.next

        self._size += 1
        return inserted

    def __setitem__(self, index: int, data: Any) -> "Node":
        inserted = self._insert(index, data)
        return inserted

    def insert(self, index, data) -> "List":
        self._insert(index, data)
        return self

    def pop(self, index: int | None = None) -> "List":
        if not self:
            raise AssertionError("Size of list is 0")
        if index is None:
            prev = self[self.size - 1]
            current = prev.next
            prev.next = None
        else:
            prev = self[index - 1]
            current = prev.next
            prev.next = prev.next.next

        self._size -= 1
        return current