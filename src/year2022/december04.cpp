#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"
#include "strings.hpp"

using namespace adventOfCode;

bool intervalsContain(const std::pair<size_t, size_t> &interval, const std::pair<size_t, size_t> &other) {
    return (interval.first >= other.first && interval.second <= other.second) ||
           (other.first >= interval.first && other.second <= interval.second);
}

bool intervalsIntersect(const std::pair<size_t, size_t> &interval, const std::pair<size_t, size_t> &other) {
    return (interval.first >= other.first && interval.first <= other.second) ||
           (other.first >= interval.first && other.first <= interval.second);
}

/**
 *  Solves the 2022-12-04 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-04
 */
std::string Year2022::december04() const {
    if (exempt("04")) {
        return "";
    }

    const std::vector<std::string> lines = fileAsLines(std::filesystem::path("input/04.txt"), false);
    std::vector<std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>>> numbers = {};

    for (const std::string &line : lines) {
        const std::vector<std::string> parts = splitString(line, ',');
        const std::vector<std::string> leftDigits = splitString(parts.at(0), '-');
        const std::vector<std::string> rightDigits = splitString(parts.at(1), '-');

        std::function<size_t(std::string)> toSize = [] (const std::string &digits) {
            return static_cast<size_t>(std::stoul(digits));
        };

        numbers.push_back({
            { toSize(leftDigits.at(0)), toSize(leftDigits.at(1)) },
            { toSize(rightDigits.at(0)), toSize(rightDigits.at(1)) }
        });
    }

    size_t points = 0;
    for (const std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> &entry : numbers) {
        points += intervalsIntersect(entry.first, entry.second) ? 1 : 0;
    }


    return std::to_string(points);
}

