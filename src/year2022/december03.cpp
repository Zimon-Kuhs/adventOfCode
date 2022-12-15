#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "collections.hpp"
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
    if (exempt("03")) {
        return "";
    }

    const size_t groupSize = 3;
    const std::vector<std::vector<std::string>> groups =
        subVectors(fileAsLines(std::filesystem::path("input/03.txt"), false), groupSize);

    std::vector<char> badges = {};
    for (const std::vector<std::string> &group : groups) {
        std::map<char, size_t> amounts = {};

        for (const std::string &item : group) {
            for (const char &character : charSet(item)) {
                if (amounts.find(character) == amounts.end()) {
                    amounts[character] = 0;
                }
                amounts[character] += 1;
            }
        }

        for (const std::pair<char, size_t> &entry : amounts) {
            if (entry.second == groupSize) {
                badges.push_back(entry.first);
                break;
            }
        }
    }

    size_t points = 0;
    for (const char &character : badges) {
        points += charPoints(character);
    }

    return std::to_string(points);
}

