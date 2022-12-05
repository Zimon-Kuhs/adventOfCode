#ifndef __ADVENT_OF_CODE_STRINGS_HPP__
#define __ADVENT_OF_CODE_STRINGS_HPP__

#include <string>
#include <vector>

namespace adventOfCode {

/**
 *  @param string       The string to split.
 *  @param delimiter    The delimiter to split on.
 *  @return             A vector containing each substring in `string` separated by `delimiter`.
 */
std::vector<std::string> splitString(const std::string &string, const char &delimiter);

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_STRINGS_HPP__
