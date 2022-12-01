"""
    Solves the 2021-12-01 problem.

    @author Zimon Kuhs
    @date   2021-12-01
    @see    https://adventofcode.com/2021/day/1
"""

import os


def solve():
    """
        Solves the problem for December 01.

        @return The solution to the problem.
    """

    return sonar_sweep(os.path.join(os.path.dirname(__file__), "data/december01.txt"), 3)


def sonar_sweep(data_path, length):
    """
        Calculates the number of times the sum of the elements of a slice of a specified length is
        greater than the previous slice of the same length.



        @param  data_path   File path to the input data consisting of newline-separated numbers.
        @param  length      The length of the slices to use for sum calculation.
        @return             The amount of slice-sums that are greater than their previous adjacent ones.
    """

    with open(data_path, "r", encoding="utf-8") as data:
        depths = [float(depth) for depth in data.readlines()]

        return len([index for index in range(0, len(depths) - length) if depths[index] < depths[index + length]])
