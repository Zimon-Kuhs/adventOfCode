#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"
#include "maths.hpp"
#include "strings.hpp"

using namespace adventOfCode;

typedef struct Command {
    int dx;
    int dy;
    size_t amount;

    std::string string() const {
        return "[" + std::to_string(dx) + ", " + std::to_string(dy) + "]: " + std::to_string(amount);
    }
} Command;

typedef struct Node {
    int x;
    int y;

    std::string string() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    bool operator<(const Node &other) const {
        return x < other.x || y < other.y;
    }
} Node;

std::vector<Command> parseCommands(const std::vector<std::string> &lines) {
    std::vector<Command> result = {};
    for (const std::string &line : lines) {
        const std::vector<std::string> parts = splitString(line, ' ');
        int dx = 0;
        int dy = 0;

        switch (parts.at(0).at(0)) {
            case 'D':
                dy = 1;
                break;
            case 'L':
                dx = -1;
                break;
            case 'R':
                dx = 1;
                break;
            case 'U':
                dy = -1;
                break;
        }
        result.push_back(Command { dx, dy, std::stoul(parts.at(1)) });
    }
    return result;
}

/**
 *  Solves the 2022-12-09 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-09
 */
std::string Year2022::december09() const {
    if (exempt("09")) {
        return "";
    }

    Node head = { 0, 0 };
    Node tail = { 0, 0 };

    std::set<Node> path = { { 0, 0 } };
    for (const Command &command : parseCommands(fileAsLines(std::filesystem::path("input/09.txt")))) {
        echo("Command: " + command.string() + ".");
        for (size_t i = 0; i < command.amount; ++i) {
            head.x += command.dx;
            head.y += command.dy;

            const int dx = tail.x - head.x;
            const int dy = tail.y - head.y;

            if (std::abs(dx) > 1) {
                tail.x += sign(dx);
            }
            if (std::abs(dy) > 1) {
                tail.y += sign(dy);
            }
            path.insert({ tail.x, tail.y });
            echo("    " + head.string());
            echo("    " + tail.string());
        }
    }

    return std::to_string(path.size());
}

