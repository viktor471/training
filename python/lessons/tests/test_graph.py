from ..structures.graph.c_style.a import Node


class TestGraph:
    def test_graph_dict(self):
        root = Node(data=1, name="v")
        root.append("a", data=3)
        assert root.data == 1
        assert root["a"].data == 3
