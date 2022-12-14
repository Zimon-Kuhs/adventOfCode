#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-10 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-10
 */
std::string Year2022::december10() const {
    if (exempt("10")) {
        return "";
    }

    return "TBI";
}

