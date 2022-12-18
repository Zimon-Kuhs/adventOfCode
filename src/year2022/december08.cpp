#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"

#define str(x) std::to_string(x)

using namespace adventOfCode;

size_t score(const std::vector<std::vector<size_t>> grid,
               const size_t &row,
               const size_t &column,
               const int &dx,
               const int &dy) {

    const int &length = static_cast<int>(grid.size());
    const size_t &tree = grid.at(row).at(column);
    const int rowEdge = dx == 1 ? length : -1;
    const int colEdge = dy == 1 ? length : -1;

    int x = static_cast<int>(row);
    int y = static_cast<int>(column);

    size_t score = 0;
    while((x = x + dx) != rowEdge && (y = y + dy) != colEdge) {
        ++score;
        if (grid.at(x).at(y) >= tree) {
            break;
        }
    }

    return score;
}

size_t score(const std::vector<std::vector<size_t>> grid, const size_t &row, const size_t &column) {
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
    std::vector<std::vector<size_t>> grid = {};

    for (const std::string &line : lines) {
        std::vector<size_t> row = {};
        for (const char &digit : line) {
            row.push_back(digit - '0');
        }
        grid.push_back(row);
    }

    const size_t &length = grid.size();
    size_t result = 0;
    for (size_t i = 1; i < length - 1; ++i) {
        for (size_t j = 1; j < length - 1; ++j) {
            result = std::max(result, score(grid, i, j));
        }
    }

    return std::to_string(result);
}

