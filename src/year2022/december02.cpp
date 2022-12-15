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

enum Result {
    Draw,
    Loss,
    Win
};

/**
 *  @param move     The move picked by the player.
 *  @param opponent The move picked by the opponent.
 *  @return         The points awarded to the player.
 */
static size_t points(Move move, Move opponent) {
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
 *  @param outcome  The desired
 *  @param opponent The move picked by the opponent.
 *  @return         The move the player should pick to get the desired outcome.
 */
static Move rig(Result outcome, Move opponent) {
    if (outcome == Draw) {
        return opponent;
    }

    if (outcome == Loss) {
        if (opponent == Scissors) {
            return Paper;
        }
        return static_cast<Move>(opponent + 1);
    }

    if (opponent == Paper) {
        return Scissors;
    }
    return static_cast<Move>(opponent - 1);
}

/**
 *  Solves the 2022-12-02 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-02
 */
std::string Year2022::december02() const {
    if (exempt("02")) {
        return "";
    }

    const std::map<std::string, std::pair<std::string, Move>> opponentMoves = {
        { "A", { "Rock",        Rock } },
        { "B", { "Paper",       Paper } },
        { "C", { "Scissors",    Scissors } },
    };
    const std::map<std::string, std::pair<std::string, Result>> results = {
        { "X", { "Loss",    Loss } },
        { "Y", { "Draw",    Draw } },
        { "Z", { "Win",     Win } },
    };

    std::vector<Move> opponent = {};
    std::vector<Move> player = {};

    for (const std::vector<std::string> &line : fileAsMatrix(std::filesystem::path("input/02.txt"), false)) {
        const Move &move = opponentMoves.at(line.at(0)).second;
        opponent.push_back(move);
        player.push_back(rig(results.at(line.at(1)).second, move));
    }

    unsigned long long result = 0;
    for (size_t i = 0; i < opponent.size(); ++i) {
        result += points(player.at(i), opponent.at(i));
    }

    return std::to_string(result);
}

