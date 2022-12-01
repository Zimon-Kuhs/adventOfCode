"""
    Tests the problems for year 2021.

    @author Zimon Kuhs
    @date   2021-12-01
"""

import os
import sys

sys.path.append(os.path.abspath("./src"))

import unittest
import year2021 as year


# pylint: disable=missing-function-docstring
class Test2021(unittest.TestCase):
    """
        Does a bunch of testing.
    """

    def test_december_01(self):
        self.assertEqual(1608, year.december01())

    def test_december_02(self):
        self.assertEqual(1942068080, year.december02())

    def test_december_03(self):
        self.assertEqual(7928162, year.december03())

    def test_december_04(self):
        self.assertEqual(6594, year.december04())

    def test_december_05(self):
        self.assertEqual("TBI", year.december05())


if __name__ == "__main__":
    unittest.main()
