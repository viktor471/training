#! /usr/bin/env python

import unittest

from calculator.calculator import Calculator

class TestCalculator(unittest.TestCase):
    def setUp(self):
        self.calc = Calculator()

    def test_add(self):
        self.assertEqual(self.calc.add(2, 3), 5,
                         "add is right")

    def test_subtract(self):
        self.assertEqual(self.calc.subtract(2, 3),
                         -1)


