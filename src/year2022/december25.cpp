#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-25 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-25
 */
std::string Year2022::december25() const {
    if (exempt("25")) {
        return "";
    }

    return "TBI";
}

