#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"

using namespace adventOfCode;

enum Move {
    Paper,
    Rock,
    Scissors
};

size_t points(Move move, Move opponent) {
    if (move == opponent) {
        return 3;
    }

    if (move == Scissors) {
        return opponent == Paper ? 8 : 1;
    }

    return move > opponent ? 8 : 1;
}

/**
 *  Solves the 2022-12-02 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-02
 */
std::string Year2022::december02() const {
    const std::map<std::string, std::pair<std::string, Move>> moves = {
        { "A", { "Rock", Rock } },
        { "B", { "Paper", Paper } },
        { "C", { "Scissors", Scissors } }
    };

    unsigned long long result = 0;
    for (const std::vector<std::string> &line : fileAsMatrix(std::filesystem::path("input/02.txt"), false)) {
        result += points(moves.at(line.at(0)).second, moves.at(line.at(1)).second);
    }

    return std::to_string(result);
}

