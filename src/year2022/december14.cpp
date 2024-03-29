#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-14 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-14
 */
std::string Year2022::december14() const {
    if (exempt("14")) {
        return "";
    }

    return "TBI";
}

