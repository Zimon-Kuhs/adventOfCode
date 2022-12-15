#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "strings.hpp"

using namespace adventOfCode;

static std::string readData() {
    std::string data = "";
    for (const std::string &line : fileAsLines(std::filesystem::path("input/06.txt"))) {
        data += line;
    }
    return data;
}

std::string findUniqueSequence(const std::string &string, const size_t &length) {
    size_t start = 0;
    size_t end = length - 1;

    while (true) {
        const std::string &sequence = string.substr(start, end);
        if (charSet(sequence).size() == sequence.length()) {
            return sequence;
        }
    }
}

/**
 *  Solves the 2022-12-06 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-06
 */
std::string Year2022::december06() const {
    if (exempt("06")) {
        return "";
    }

    return findUniqueSequence(readData(), 4);
}

