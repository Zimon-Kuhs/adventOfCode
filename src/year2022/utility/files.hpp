#ifndef __ADVENT_OF_CODE_FILES_HPP__
#define __ADVENT_OF_CODE_FILES_HPP__

#include <filesystem>
#include <vector>

namespace adventOfCode {

/**
 *  @param file         The file to read.
 *  @param keepEmpty    Flag specifying whether to keep empty lines, default `true`.
 *  @return             The contents of `file` as a vector of line strings.
 */
std::vector<std::string> fileAsLines(const std::filesystem::path &file, const bool &keepEmpty = true);

/**
 *  @param file         The file to read.
 *  @param keepEmpty    Flag specifying whether to keep empty lines, default `true`.
 *  @return             The contents of `file` as a 2D vector with text entries.
 */
std::vector<std::vector<std::string>> fileAsMatrix(const std::filesystem::path &file, const bool &keepEmpty = true);

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_FILES_HPP__
