import pytest

import json
import logging
from datetime import datetime


@pytest.fixture()
def dif_time():
    print("fixture dif_time scope function")
    return datetime.now()

@pytest.fixture(autouse=True)
def autouse_fixture():
    print("fixture autouse")

@pytest.fixture(scope="class")
def scope_class_time():
    print("fixture scope class")
    return datetime.now()

@pytest.fixture(scope="session")
def same_time():
    print("fixture same_time scope session")
    return datetime.now()

def test_1(dif_time, same_time, scope_class_time):
    print("test_1")
    print(dif_time)
    print(same_time)
    print(scope_class_time)

def test_2(dif_time, same_time, scope_class_time):
    print("test_3")
    print(dif_time)
    print(same_time)
    print(scope_class_time)

def test_3(scope_class_time):
    print(scope_class_time)


@pytest.mark.usefixtures("scope_class_time")
class TestCalculatorClass:
    def test_a(self, dif_time):
        print("test_a")
        print(scope_class_time)
        print(dif_time)
        print(same_time)

    def test_b(self):
        print("test_b")
        print(scope_class_time)
        print(same_time)


