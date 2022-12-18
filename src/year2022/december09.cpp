#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-09 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-09
 */
std::string Year2022::december09() const {
    if (exempt("09")) {
        return "";
    }

    std::vector<std::string> input = fileAsLines(std::filesystem::path("input/09.txt"));

    return "TBI";
}

