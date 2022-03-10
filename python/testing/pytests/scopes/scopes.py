import pytest

import json
import logging
from datetime import datetime


@pytest.fixture()
def dif_time():
    print()
    print("fixture dif_time")
    return datetime.now()


def test_1(dif_time):
    print(dif_time)

def test_2(dif_time):
    print(dif_time)

@pytest.fixture(scope="class")
def scope_class_time():
    print()
    print("fixture scope_class_time")
    return datetime.now()

@pytest.mark.usefixtures("scope_class_time")
class TestCalculatorClass:
    def test_a(self):
        print(scope_class_time)
        print("test_a")

    def test_b(self):
        print(scope_class_time)
        print("test_b")

