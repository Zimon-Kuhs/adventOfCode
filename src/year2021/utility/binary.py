"""
    Utility functions for binary operations.

    @author Zimon Kuhs
    @date 2021-12-03
"""


def parse_binary(string_input):
    """
        @param string_input A list of strings, or a string.
        @return             The input string(s) converted to binary numbers.
    """

    is_list = isinstance(string_input, list)

    result = [int(number, base=2) for number in (string_input if is_list else [string_input])]
    return result if is_list else result[0]
