#ifndef __ADVENT_OF_CODE_FILES_HPP__
#define __ADVENT_OF_CODE_FILES_HPP__

#include <filesystem>
#include <vector>

namespace adventOfCode {

/**
 *  @param file The file to read.
 *  @return     The contents of `file` as a vector of line strings.
 */
std::vector<std::string> fileAsLines(const std::filesystem::path &file, const bool &keepEmpty = true);

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_FILES_HPP__
