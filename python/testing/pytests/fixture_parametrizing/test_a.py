import pytest
import logging


@pytest.fixture
def timeline(var):
    logging.info(f"var: {var}")


@pytest.mark.parametrize('var', ["a", "b"])
def test_timeline(var, timeline):
    # for instance in timeline.instances:
        # assert instance % 2 == 0
    assert True
