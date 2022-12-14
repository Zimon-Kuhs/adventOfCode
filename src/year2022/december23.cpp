#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-23 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-23
 */
std::string Year2022::december23() const {
    if (exempt("23")) {
        return "";
    }

    return "TBI";
}

