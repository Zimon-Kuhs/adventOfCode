#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-12 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-12
 */
std::string Year2022::december12() const {
    if (exempt("12")) {
        return "";
    }

    return "TBI";
}

