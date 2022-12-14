#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "yearYYYY.hpp"

using namespace adventOfCode;

/**
 *  Solves the YYYY-12-DD problem.

 *  @author Zimon Kuhs
 *  @date   YYYY-12-DD
 */
std::string YearYYYY::decemberDD() const {
    if (exempt("DD")) {
        return "";
    }

    return "TBI";
}
