#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"
#include "strings.hpp"

using namespace adventOfCode;

typedef struct StackMove {
    const size_t amount;
    const size_t from;
    const size_t to;
} StackMove;

std::pair<std::vector<std::stack<char>>, std::vector<StackMove>> parseInput() {
    const std::vector<std::string> lines = fileAsLines(std::filesystem::path("input/05.txt"));
    std::vector<std::string> first = {};
    std::vector<std::string> second = {};

    /*
     *  The delimiter between the initial state and the moves is an empty line.
     *  Parse until encountered into the first half, and the rest into the second half.
     *  Ignore the empty line itself.
     */

    size_t i = 0;
    std::string parsed = "";
    for (; !(parsed = lines.at(i)).empty(); ++i) {
        first.push_back(parsed);
    }

    for (i += 1; i < lines.size(); ++i) {
        second.push_back(lines.at(i));
    }

    const size_t size = parseNumbers(first.back()).back();
    first.pop_back();
    std::reverse(first.begin(), first.end());
    std::vector<std::stack<char>> stacks = std::vector<std::stack<char>>(size, std::stack<char>());

    /*
     *  Each possible stack entry is 3 characters, step by 4 to account for the space between them.
     *  It's only required to look at the first character of each 4-character segment,
     *  since if it's '[' we have an entry at the next (i + 1) position.
     */
    for (const std::string &line : first) {
        for (size_t i = 0; i < line.size(); i += 4) {
            if (line.at(i) == '[') {
                stacks.at(i / 4).push(line.at(i + 1));
            }
        }
    }

    std::vector<StackMove> moves = {};
    for (const std::string &line : second) {
        const std::vector<size_t> numbers = parseNumbers(line);
        if (numbers.size() != 3) {
            throw std::runtime_error("Invalid line while parsing moves: \"" + line + "\"");
        }

        moves.push_back({ numbers.at(0), numbers.at(1), numbers.at(2) });
    }

    return { stacks, moves };
}

/**
 *  Solves the 2022-12-05 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-05
 */
std::string Year2022::december05() const {
    if (exempt("05")) {
        return "";
    }

    const std::pair<std::vector<std::stack<char>>, std::vector<StackMove>> input = parseInput();
    std::vector<std::stack<char>> stacks = input.first;
    std::vector<StackMove> moves = input.second;

    for (const StackMove &move : moves) {
        std::stack<char> &source = stacks.at(move.from - 1);
        std::stack<char> &target = stacks.at(move.to - 1);

        std::stack<char> crates = {};
        for (size_t i = 0; i < move.amount; ++i) {
            crates.push(source.top());
            source.pop();
        }
        while (!crates.empty()) {
            target.push(crates.top());
            crates.pop();
        }
    }

    std::string result = "";
    for (const std::stack<char> stack : stacks) {
        result += stack.top();
    }

    return result;
}

