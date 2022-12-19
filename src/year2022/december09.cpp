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

    std::vector<Node> nodes = std::vector<Node>(10, { 0, 0 });
    Node &head = nodes.front();
    Node &tail = nodes.back();

    std::set<std::string> path = { "0_0" };
    for (const Command &command : parseCommands(fileAsLines(std::filesystem::path("input/09.txt")))) {
        for (size_t i = 0; i < command.amount; ++i) {
            head.x += command.dx;
            head.y += command.dy;

            for (size_t j = 1; j < nodes.size(); ++j) {
                Node &segment = nodes.at(j);
                Node &previous = nodes.at(j - 1);

                const int dx = segment.x - previous.x;
                const int dy = segment.y - previous.y;
                const int xShift = sign(dx);
                const int yShift = sign(dy);
                const unsigned int adx = std::abs(dx);
                const unsigned int ady = std::abs(dy);

                if (adx + ady > 2) {
                    segment.x += xShift;
                    segment.y += yShift;
                } else if (adx > 1) {
                    segment.x += xShift;
                } else if (ady > 1) {
                    segment.y += yShift;
                }
            }

            path.insert(std::to_string(tail.x) + "_" + std::to_string(tail.y));
        }
    }

    return std::to_string(path.size());
}

