#! /usr/bin/env python

#import sys
#sys.path.insert(1, "../my_sum")


from my_sum.my_sum import my_sum, subtract

from unittest import TestCase
import unittest

class TestSum(TestCase):

    def test_sum(self):
        self.assertEqual(my_sum(2, 3), 5)
    
    def test_subtract(self):
        self.assertEqual(subtract(2, 3), 2)


if __name__ == "__main__":
    unittest.main()

