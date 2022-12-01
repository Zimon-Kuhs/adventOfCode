"""
    Solves the 2021-12-04 problem.

    @author Zimon Kuhs
    @date   2021-12-05
    @see    https://adventofcode.com/2021/day/4
"""


from .utility import Board, parse_problem, ParseError


def find_winner(boards, draws, loser=False):
    """
        Find the winner of a bingo game.

        @param boards   The boards in play.
        @param draws    The list of drawn numbers, in order.
        @return         The board score (last drawn number multiplied by the sum of non-checked numbers in the board).
        @see            .utility.Board
    """

    index = 0
    indices = []
    the_boards = {}
    for board in boards:
        the_boards[index] = board
        index += 1

    for draw in draws:
        for index, board in the_boards.items():
            if index in indices:
                continue

            if board.check(draw):
                if not loser or len(indices) == len(the_boards) - 1:
                    return draw * board.sum_cells(checked=False)
                indices.append(index)


def solve():
    """
        Solves the problem for December 04.

        @return the solution to the problem.
    """

    lines = parse_problem(__name__)
    draws = [int(number) for number in lines.pop(0).split(",")]

    boards = []
    while len(lines) >= 5:
        board_lines, lines = lines[1:6], lines[6:]
        boards.append(Board(board_lines))

    if len(lines):
        raise ParseError(f"{len(lines)} lines left!")

    return find_winner(boards, draws, loser=True)
