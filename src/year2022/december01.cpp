#include <algorithm>

#include "year2022.hpp"
#include "collections.hpp"
#include "files.hpp"
#include "log.hpp"

#define MAX_ELVES 3

using namespace adventOfCode;

std::vector<size_t> highest(const std::vector<size_t> elements, const size_t &amount) {

    const size_t numberOfElements = elements.size();
    if (amount > numberOfElements) {
        throw std::runtime_error("Amount too high: " + std::to_string(amount));
    }

    std::vector<size_t> highest = std::vector<size_t>(elements);
    if (amount == numberOfElements) {
        return highest;
    }

    std::sort(highest.rbegin(), highest.rend());
    highest.erase(highest.begin() + amount, highest.end());

    return highest;
}

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

    std::vector<size_t> sums = {};
    for (const std::vector<size_t> food : calories) {
        sums.push_back(vectorSum(food));
    }

    return std::to_string(vectorSum(highest(sums, MAX_ELVES)));
}

