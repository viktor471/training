#! /usr/bin/env python

import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        return self.assertEqual(2+3, 5)

    def test_subtract(self):
        return self.assertEqual(2 - 3, 1)


if __name__ == "__main__":
    unittest.main()
