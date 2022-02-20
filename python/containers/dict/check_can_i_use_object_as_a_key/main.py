
class Pair:
    signal: str
    command: str

    def __init__(self, pair: list[2]):
        self.signal = pair[0]
        self.command = pair[1]

dictionary = {}

dictionary[Pair(["a", "b"])] = 1
dictionary[Pair(["a", "b"])] = 2

print(dictionary)