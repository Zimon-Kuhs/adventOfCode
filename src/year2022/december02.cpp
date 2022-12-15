#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-02 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-02
 */
std::string Year2022::december02() const {
    if (exempt("02")) {
        return "";
    }

    return "TBI";
}

