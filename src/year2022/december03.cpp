#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"

using namespace adventOfCode;

size_t charPoints(const char &character) {
    size_t ascii = int(character);

    if (ascii < 65 || ascii > 122 || (ascii > 90 && ascii < 97)) {
        throw std::runtime_error("Not an alphabetic character: '" + std::to_string(character) + "'");
    }

    return ascii > 90 ? (ascii - 96) : (ascii - 38);
}

/**
 *  Solves the 2022-12-03 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-03
 */
std::string Year2022::december03() const {
    std::vector<std::pair<std::string, std::string>> rucksacks = {};
    for (const std::string &line : fileAsLines(std::filesystem::path("input/03.txt"), false)) {
        const size_t midPoint = line.length() / 2;
        rucksacks.push_back({ line.substr(0, midPoint), line.substr(midPoint) });
    }

    std::vector<char> commons = {};
    for (const std::pair<std::string, std::string> &entry : rucksacks) {
        for (const char &character : entry.first) {
            if (entry.second.find(character) != std::string::npos) {
                commons.push_back(character);
                break;
            }
        }
    }

    const size_t &expectedSize = rucksacks.size();
    const size_t &actualSize = commons.size();
    if (expectedSize != actualSize) {
        throw std::runtime_error("Error parsing common characters; expected found: " + std::to_string(expectedSize) +
                                 " actual found: " + std::to_string(actualSize));
    }

    size_t points = 0;
    for (const char &character : commons) {
        points += charPoints(character);
    }

    return std::to_string(points);
}

