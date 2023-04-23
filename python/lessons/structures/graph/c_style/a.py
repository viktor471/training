import copy
from dataclasses import dataclass
from typing import Any, Optional


class Node:
    @dataclass
    class AddedNodes:
        by_name: dict
        by_id: dict

        def append(self, name, node):
            if (
                self.added_nodes.by_name[name] == id(node)
                and self.added_nodes.by_id[id(node)] == name
            ) or (
                name not in self.added_nodes.by_name
                and id(node) not in self.added_nodes.by_id
            ):
                self.connections[name] = node
                assert self.added_nodes.by_name[name] == id(node)
                assert self.added_nodes.by_id[id(node)] == name

    added_nodes = AddedNodes({}, {})

    def __init__(
        self, name: str, connections: dict | None = None, data: Any | None = None
    ):
        if connections is None:
            self.connections = {}
        else:
            self.connections = copy.deepcopy(connections)

        self.data = data
        self.added_nodes.by_name[name] = id(self)

    def append(
        self, name: str, data: Any | None = None, node: Optional["Node"] = None
    ) -> "Node":
        assert data is None or node is None
        assert data is not None or node is not None

        if data is not None:
            node = Node(data=data)

        self.added_nodes.append(name, node)
        self.connections[name]

        return self

    def dict(self) -> dict:
        return dict(connections=self.connections, data=self.data)

    def __repr__(self) -> str:
        return f"Node(connections={self.connections}, data={self.data})"

    def __str__(self) -> str:
        return f"{self.dict()}"

    def __getitem__(self, item: str) -> "Node":
        return self.connections.get(item, None)

    def __setitem__(self, item: str, node: "Node") -> "Node":
        assert isinstance(Node, type(self))
        self.connections[item] = node
        return node
