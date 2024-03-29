#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-21 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-21
 */
std::string Year2022::december21() const {
    if (exempt("21")) {
        return "";
    }

    return "TBI";
}

