#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"
#include "strings.hpp"

using namespace adventOfCode;

/**
 *  @param character    The character which points to calculate.
 *  @return             The arbitrary amount of points for the character.
 */
size_t charPoints(const char &character) {
    size_t ascii = int(character);

    if (std::isupper(character)) {
        return ascii - 38;
    } else if (std::islower(character)) {
        return ascii - 96;
    }

    throw std::runtime_error("Not an alphabetic character: '" + std::to_string(character) + "'");
}

/**
 *  Solves the 2022-12-03 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-03
 */
std::string Year2022::december03() const {
    std::vector<std::pair<std::string, std::string>> rucksacks = {};
    for (const std::string &line : fileAsLines(std::filesystem::path("input/03.txt"), false)) {
        const std::vector<std::string> parts = divideString(line, 2);
        rucksacks.push_back({ parts.at(0), parts.at(1) });
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

