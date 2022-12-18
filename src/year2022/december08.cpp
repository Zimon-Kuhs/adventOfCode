#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "grid.hpp"
#include "log.hpp"

using namespace adventOfCode;

size_t score(Grid<size_t> &grid, const size_t &row, const size_t &column, const int &dy, const int &dx) {
    grid.set(row, column);
    const size_t &tree = grid.current();

    size_t score = 0;
    while(grid.move(dy, dx)) {
        ++score;
        if (grid.current() >= tree) {
            break;
        }
    }

    return score;
}

size_t score(Grid<size_t> &grid, const size_t &row, const size_t &column) {
    return score(grid, row, column,  0,  1) *
           score(grid, row, column,  0, -1) *
           score(grid, row, column,  1,  0) *
           score(grid, row, column, -1,  0);
}

/**
 *  Solves the 2022-12-08 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-08
 */
std::string Year2022::december08() const {
    if (exempt("08")) {
        return "";
    }

    const std::vector<std::string> lines = fileAsLines(std::filesystem::path("input/08.txt"));
    std::vector<std::vector<size_t>> numbers = {};

    for (const std::string &line : lines) {
        std::vector<size_t> row = {};
        for (const char &digit : line) {
            row.push_back(digit - '0');
        }
        numbers.push_back(row);
    }

    Grid grid = Grid(numbers);
    if (!grid.square()) {
        throw std::runtime_error("Expected square grid! Dimensions are: " +
                                 std::to_string(grid.height()) + " x " +
                                 std::to_string(grid.width()));
    }

    size_t result = 0;
    for (size_t i = 1; i < grid.height() - 1; ++i) {
        for (size_t j = 1; j < grid.width() - 1; ++j) {
            result = std::max(result, score(grid, i, j));
        }
    }

    return std::to_string(result);
}

