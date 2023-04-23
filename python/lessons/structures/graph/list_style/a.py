class Graph:
    def __init__(self, initial_state: list[list[int]] = None):
        if initial_state is not None:
            assert isinstance(initial_state, list)

            for neighborhood in initial_state:
                assert isinstance(neighborhood, list)

                for weight in neighborhood:
                    assert isinstance(weight, int)

        else:
            self._initial_state = []
