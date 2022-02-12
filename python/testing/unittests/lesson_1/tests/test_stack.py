#! /usr/bin/env python

from ds.stack import Stack

import pytest

@pytest.fixture
def stack():
    return Stack()

def test_is_instance_stack():
    s = Stack()
    assert isinstance(s, Stack)

def test_len_equal_zero():
    s = Stack()
    assert len(s) == 0

def test_push(stack):
    stack.push(1)
    assert len(stack) == 1

    stack.push(2)
    assert len(stack) == 2

def test_pop(stack):
    stack.push("hello")
    stack.push("world")

    assert stack.pop() == "world"
    assert stack.pop() == "hello"
    assert stack.pop() is None
