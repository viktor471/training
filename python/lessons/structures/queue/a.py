from typing import Any, Optional, Sequence


class Queue:
    class Node:
        def __init__(self, data: Any, next_: Optional["Queue.Node"] = None):
            self.data = data
            self.next = next_

        def __eq__(self, another) -> bool:
            match another:
                case Queue.Node():
                    return self.data == another.data
                case _:
                    return self.data == another

    def append(self, data) -> "Queue.Node":
        if self._tail is not None:
            self._tail.next = Queue.Node(data)
            self._tail = self._tail.next
        else:
            self._tail = self._head = Queue.Node(data)
        self._size += 1
        return self

    def pop(self) -> "Queue.Node":
        if self._head is None:
            raise IndexError("queue is empty")

        head = self._head
        self._head = head.next
        self._size -= 1
        return head

    def __len__(self) -> int:
        return self.size

    def __bool__(self) -> bool:
        return bool(self.size)

    @property
    def size(self) -> int:
        return self._size

    def __init__(self, seq: Sequence | None = None):
        self._head = None
        self._tail = None
        self._size = 0

        if seq is not None:
            for el in seq:
                self.append(el)
