"""
    File management utilities.

    @author Zimon Kuhs
    @date   2021-12-01
"""

from os.path import basename, dirname, join, realpath

from .binary import *
from .collections import *
from .errors import *


def parse_problem(script):
    """
        TODO:
            - Move to another file?

        @return All lines in a file as a list.
    """

    base = basename(script).split(".")[1]
    path = realpath(join(dirname(__file__), "..", "data", f"{base}.txt"))

    with open(path, "r", encoding="utf-8") as stuff:
        return stuff.read().split("\n")[:-1]
