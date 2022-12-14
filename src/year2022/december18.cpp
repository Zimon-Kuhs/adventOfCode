#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-18 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-18
 */
std::string Year2022::december18() const {
    if (exempt("18")) {
        return "";
    }

    return "TBI";
}

