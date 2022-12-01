"""
    Solves the 2021-12-02 problem.

    @author Zimon Kuhs
    @date   2021-12-02
    @see    https://adventofcode.com/2021/day/2
"""

import os

VALID_COMMANDS = [
    "down",
    "forward",
    "up",
]


def position(input_list, depth=0, length=0, aim=0):
    """
        Calculates the current position based on a collection of commands.

        @param input_list   The list of command strings.
        @param depth        The initial depth.
        @param length       The initial length.
        @param aim          The initial aim.
        @return             The current position based on the "executed" commands.
    """

    if (depth | length) < 0:
        raise ValueError(f"Invalid starting position ({depth}, {length})")

    for line in input_list:
        command, magnitude, *remainder = line.split()

        if remainder:
            raise ValueError(f"Too many entries in command: {command}")
        if command not in VALID_COMMANDS:
            raise ValueError(f"Invalid command: {command}")

        mod = int(magnitude)
        if command == "down":
            aim += mod
        elif command == "forward":
            length += mod
            depth += mod * aim
        elif command == "up":
            aim -= mod

    return depth, length


def solve():
    """
        Solves the problem for December 02.

        @return The solution to the problem.
    """

    the_path = os.path.join(os.path.dirname(__file__), "data/december02.txt")

    with open(the_path, "r", encoding="utf-8") as data:
        depth, length = position(data.readlines())

    return depth * length
