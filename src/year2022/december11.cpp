#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-11 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-11
 */
std::string Year2022::december11() const {
    if (exempt("11")) {
        return "";
    }

    return "TBI";
}

