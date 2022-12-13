#ifndef __ADVENT_OF_CODE_STRINGS_HPP__
#define __ADVENT_OF_CODE_STRINGS_HPP__

#include <string>
#include <vector>

namespace adventOfCode {

/**
 *  Splits a string into a number of parts, biased towards leftmost segments.
 *  <p>
 *  E.g. divideString("ABCDEFGHIJ", 3) will yield { "ABCD", "EFG", "HIJ" };
 *
 *  @param string   The string to split.
 *  @param parts    How many segments to split the string into.
 *  @return         Vector containing the parts of the string.
 */
std::vector<std::string> divideString(const std::string &string, const size_t &parts);

/**
 *  @param string       The string to split.
 *  @param delimiter    The delimiter to split on.
 *  @return             A vector containing each substring in `string` separated by `delimiter`.
 */
std::vector<std::string> splitString(const std::string &string, const char &delimiter);

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_STRINGS_HPP__
