#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-20 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-20
 */
std::string Year2022::december20() const {
    if (exempt("20")) {
        return "";
    }

    return "TBI";
}

