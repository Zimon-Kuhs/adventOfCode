#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"

using namespace adventOfCode;

enum Move {
    Paper,
    Rock,
    Scissors
};

size_t points(Move move, Move opponent) {
    const size_t base = std::map<Move, size_t>{
        { Paper,    2 },
        { Rock,     1 },
        { Scissors, 3 }
    }[move];

    if (move == opponent) {
        return base + 3;
    }

    size_t outcome = 0;
    switch(move) {
        case Paper:
            outcome = opponent == Rock ? 6 : 0;
            break;
        case Rock:
            outcome = opponent == Scissors ? 6 : 0;
            break;
        case Scissors:
            outcome = opponent == Paper ? 6 : 0;
            break;
    }

    return base + outcome;
}

/**
 *  Solves the 2022-12-02 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-02
 */
std::string Year2022::december02() const {
    const std::map<std::string, std::pair<std::string, Move>> opponentMoves = {
        { "A", { "Rock",        Rock } },
        { "B", { "Paper",       Paper } },
        { "C", { "Scissors",    Scissors } },
    };
    const std::map<std::string, std::pair<std::string, Move>> playerMoves = {
        { "X", opponentMoves.at("A") },
        { "Y", opponentMoves.at("B") },
        { "Z", opponentMoves.at("C") }
    };

    unsigned long long result = 0;
    for (const std::vector<std::string> &line : fileAsMatrix(std::filesystem::path("input/02.txt"), false)) {
        result += points(playerMoves.at(line.at(1)).second, opponentMoves.at(line.at(0)).second);
    }

    return std::to_string(result);
}

