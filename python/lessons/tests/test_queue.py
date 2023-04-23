from ..structures.queue.a import Queue


class TestQueue:
    def test_queue_init(self):
        data = [1, 2, 3]
        queue = Queue(data)

        assert queue.size == 3
        assert len(queue) == 3

        iterator = iter(data)

        while queue:
            assert queue.pop().data == next(iterator)

    def test_queue_append_pop(self):
        queue = Queue()

        data = [1, 2, 3, 4]

        for el in data:
            queue.append(el)

        assert len(queue) == 4

        for el in data:
            assert queue.pop() == el
