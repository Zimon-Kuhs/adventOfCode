"""
    Solves the 2021-12-05 problem.

    @author Zimon Kuhs
    @date   2021-12-05
"""


from year2021.utility import parse_problem


def solve():
    """
        Solves the problem for December 05.

        @return the solution to the problem.
    """

    vectors = [(coords[0], coords[1]) for line in parse_problem(__name__) for coords in line.split(" -> ")]

    if False is True:
        print(vectors)

    return "TBI"
