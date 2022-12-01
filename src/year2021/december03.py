"""
    Solves the 2021-12-03 problem.

    @author Zimon Kuhs
    @date   2021-12-03
    @see    https://adventofcode.com/2021/day/3
"""

from functools import reduce
from .utility import column_count, most_common, parse_binary, parse_problem


def rating(lines, high):
    """
        Calculates the rating for a list of data.

        @param lines    The list of data.
        @param most     Whether to pick the highest (True) value, or the lowest (False).
        @param prefer   The value to prefer in the case of a tie.
    """

    array = lines.copy()

    index = 0
    while len(array) > 1:
        char = most_common(column_count(array, index), most=high, prefer=("1" if high else "0"))
        array = [line for line in array if line[index] is char]
        index += 1

    return parse_binary(array[0])


def solve():
    """
        Solves the problem for December 03.

        @return the solution to the problem.
    """

    lines = parse_problem(__name__)

    return reduce((lambda x, y: x * y), [rating(lines, highest) for highest in [True, False]])


""" ************************************************** First half ************************************************* """


def character_vote(string_list):
    """
        Builds a string from the most common characters in a list of strings, per index.

        @param string_list  The list of strings.
        @return             A string where at every index the character is the most common by index.
    """

    index = 0
    result = []

    while index < max([len(x) for x in string_list]):
        result.append(most_common(column_count(string_list, index)))
        index += 1

    return "".join(result)


def invert(binary):
    """
        @param binary   The string to invert.
        @return         The input string binary-inverted.
    """

    return "".join({"0": "1", "1": "0"}[digit] for digit in binary)


def first_half():
    """
        Solves the first half of the problem.

        @return The solution to the first part of the problem.
    """

    gamma_string = character_vote(parse_problem(__name__))
    gamma = parse_binary(gamma_string)
    epsilon = parse_binary(invert(gamma_string))

    return gamma * epsilon


""" *************************************************************************************************************** """
