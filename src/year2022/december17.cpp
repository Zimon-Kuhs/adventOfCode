#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-17 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-17
 */
std::string Year2022::december17() const {
    if (exempt("17")) {
        return "";
    }

    return "TBI";
}

