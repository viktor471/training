from typing import Any, Optional
from pydantic import BaseModel

class List(BaseModel):
    data: Any | None = None
    next: Optional["List"] = None

    _size: int = 0
    _tail: "List" = None

    @property
    def size(self) -> int:
        return self._size

    @property
    def tail(self):
        if self._tail is None:
            return self
        else:
            return self._tail

    def append(self, data: Any) -> "List":
        self.tail.next = List(data = data)

        self._size += 1

        self._tail = self.tail.next

        return self

    @property
    def head(self) -> "List":
        return self

    def prepend(self, data) -> "List":
        head = self.head
        self.next = head
        self.data = data

        return self

    def __getitem__(self, index: int) -> "List":
        current = self
        i = 0
        while i < self.size:
            if i == index:
                break
            i += 1
            current = current.next
        else:
            raise AssertionError("index out of range")

        return current

    def insert(self, data, index) -> "List":
        prev = self[index - 1]
        inserted = List(data = data, next = prev.next)
        prev.next = inserted

        return self

    def pop(self, index: int | None = None) -> "List":
        if index is None:
            prev = self[self.size -1]
        else:
            prev = self[self.index - 1]

        current = prev.next
        prev.next = None
        return current



def print_list(list_: List):
    next_ = list_

    while next_ is not None:
        print(next_.data)
        next_ = next_.next

def fill_list(list_: List) -> List:
    next_ = list_
    for i in range(10):
        next_.data = i
        if i != 9:
            next_.next = List()
            next_ = next_.next

list_ = List()
fill_list(list_)

print_list(list_)