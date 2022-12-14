#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-15 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-15
 */
std::string Year2022::december15() const {
    if (exempt("15")) {
        return "";
    }

    return "TBI";
}

