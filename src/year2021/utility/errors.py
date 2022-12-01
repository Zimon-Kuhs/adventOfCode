"""
    Custom errors.

    @author Zimon Kuhs
    @date   2021-12-05
"""


class ParseError(Exception):
    """
        Represents error during parsing of anything.
    """

    # @Override
    def __init__(self, value):
        self.value = value
        super().__init__(self, value)

    # @Override
    def __str__(self):
        return repr(self.value)
