#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-04 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-04
 */
std::string Year2022::december04() const {
    if (exempt("04")) {
        return "";
    }

    return "TBI";
}

