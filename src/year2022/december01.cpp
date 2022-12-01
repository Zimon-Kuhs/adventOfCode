#include "year2022.hpp"
#include "collections.hpp"
#include "files.hpp"
#include "log.hpp"

#define MAX_ELVES

using namespace adventOfCode;

/**
 *  Solves the 2022-12-01 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-01
 */
std::string Year2022::december01() const {

    std::vector<std::string> input = fileAsLines(std::filesystem::path("input/01.txt"));
    while (input.at(0).empty()) {
        input.erase(input.begin());
    }

    std::vector<std::vector<size_t>> calories = {};
    std::vector<size_t> elf = {};

    for (const std::string &line : input) {
        if (line.empty()) {
            calories.push_back(elf);
            elf = {};
        } else {
            elf.push_back(std::stoul(line));
        }
    }

    size_t maxValue = 0;
    std::vector<size_t> sums = {};
    for (const std::vector<size_t> food : calories) {
        const size_t total = vectorSum(food);

        if (total > maxValue) {
            maxValue = total;
        }
        sums.push_back(total);
    }

    return std::to_string(maxValue);
}

