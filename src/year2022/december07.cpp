#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-07 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-07
 */
std::string Year2022::december07() const {
    if (exempt("07")) {
        return "";
    }

    return "TBI";
}

