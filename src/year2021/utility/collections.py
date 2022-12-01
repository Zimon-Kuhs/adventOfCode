"""
    Utility functions for collections.

    TODO:
        - Own file for classes maybe?

    @author Zimon Kuhs
    @date 2021-12-03

"""

# pylint: disable=use-a-generator

import sys


class Board:
    """
        Class for a bingo board.
        <p>
        I might've gone overBoard (hehu) with it.
        <p>
        TODO:
            - There might be a solution where the rows and columns checked are "tallied" so that a complete
              row/column-wise check does not have to be performed every single time a number is checked.

        @attribute board        List of list containing the numbers.
        @attribute my_string    The string representation of the board.
        @attribute rows         The number of rows in the board.
        @attribute widths       The rows' widths.
    """

    def __init__(self, lines):
        self.board = []
        self.checked = []
        self.numbers = {}

        for line in lines:

            array = []
            for number in [int(number) for number in line.split()]:
                array.append(number)

            self.board.append(array)

        for row, _ in enumerate(self.board):

            array = []
            for column, number in enumerate(self.board[row]):
                array.append(False)
                self.numbers[number] = (row, column)

            self.checked.append(array)

        self.my_string = str(self.board)

    def check(self, number):
        """
            Marks a cell.

            @param number   The number to mark.
            @return         True if marking the number completed the bord, False otherwise.
        """

        if number not in self.numbers:
            return False

        row, column = self.numbers[number]
        self.checked[row][column] = True

        if self.row_complete(row) or self.column_complete(column):
            return True

        return False

    def row_complete(self, row):
        """
            Checks whether or not the specified row is fully marked.

            @param row  The row to check.
            @return     True if the row is fully checked, False otherwise.
        """

        return all([check for check in self.checked[row]])

    def column_complete(self, column):
        """
            Checks whether or not the specified column is fully marked.

            @param column   The column to check.
            @return         True if the column is fully checked, False otherwise.
        """

        return all([self.checked[row][column] for row, _ in enumerate(self.board)])

    def sum_cells(self, checked=False):
        """
            @param checked  Flag specifying whether to sum checked or unchecked cells.
            @return         The sum of the numbers in all unchecked cells.
        """

        return sum([number
                    for row, _ in enumerate(self.board)
                    for column, number in enumerate(self.board[row])
                    if self.checked[row][column] is checked])

    # @Override
    def __str__(self):
        return self.my_string


def column_count(matrix, column=0):
    """
        Calculates the column-wise number of occurences in a matrix.
        <p>
        N.B. will operator on jagged matrices; rows that are not long enough to have an element at the column index
        are simply ignored, since only occurences are relevant.

            TODO:
                - I would really want this bad boy to be a class but this is Python and I'm (~~efficient~~) lazy.

        @param matrix   The array of arrays which elements to check.
        @param column   The column to check.
        @return         A dictionary element -> amount specifying the number of times
                        the elements occured in the column.
    """

    frequencies = {}
    for array in matrix:
        if len(array) < column:
            continue

        element = array[column]

        if element not in frequencies:
            frequencies[element] = 0

        frequencies[element] += 1

    return frequencies


def most_common(frequency_map, most=True, prefer=None):
    """
        Find the most frequent character in a frequency map.

        TODO:
            - Can be generalized.

        @param frequency_map    The frequency map as described by #frequency_map(list, int).
        @param most             If True, the most frequent character is selected, otherwise the least frequent.
        @param prefer           In the case where
    """

    compare = sys.maxsize * (-1 if most else 1)
    result = ''

    #   I have a feeling there's a one-liner here, but can't think of the movie.
    for char, amount in frequency_map.items():

        # I'm well aware this can be done a few magnitudes more readable, but it's hilarious to me that this works.
        # pylint: disable=too-many-boolean-expressions
        if most and amount > compare or \
            not most and amount < compare or\
                amount is compare and result is not prefer and \
                result not in prefer and (char is prefer or char in prefer):

            compare = amount
            result = char

    return result
