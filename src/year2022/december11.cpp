#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "collections.hpp"
#include "files.hpp"
#include "maths.hpp"
#include "strings.hpp"

#define toStr(x) std::to_string(x)

using namespace adventOfCode;

typedef struct Operation {
    const char operation;
    const bool self;
    const size_t value;

    size_t run(const size_t &old) {
        return mathOperation(old, operation, self ? old : value);
    }

} Operation;

class Monkey {
    public:
        Monkey(const std::vector<size_t> &items,
               Operation operation,
               const size_t &divisor,
               const std::pair<size_t, size_t> &targets) :
                items(items),
                targets(targets),
                divisor(divisor),
                operation(operation),
                moves(0) {}

        void inspect(std::vector<Monkey> &monkeys) {
            for (const size_t &item : items) {
                const size_t newValue = static_cast<size_t>(operation.run(item) / 3);
                size_t receiver = newValue % divisor == 0 ? targets.first : targets.second;
                monkeys.at(receiver).toss(newValue);
                ++moves;
            }
            items.clear();
        }

        size_t inspections() const {
            return moves;
        }
size_t operate(const size_t value) { return operation.run(value); }
std::vector<size_t> itemz() { return items; }
    private:
        void toss(const size_t &item) {
            items.push_back(item);
        }

        std::vector<size_t> items;
        const std::pair<size_t, size_t> targets;
        const size_t divisor;
        Operation operation;
        size_t moves;
};

std::vector<Monkey> parseMonkeys() {
    std::vector<std::vector<std::string>> blocks = {{}};
    for (const std::string &line : fileAsLines(std::filesystem::path("input/11.txt"))) {
        if (line.empty()) {
            blocks.push_back({});
            continue;
        }
        blocks.back().push_back(line);
    }

    for(const std::vector<std::string> &block : blocks) {
        echo(block);
    }

    std::vector<Monkey> result = {};
    for (const std::vector<std::string> block : blocks) {
        const std::vector<std::string> operation = splitString(block.at(2), ' ');
        const bool self = operation.at(3) == "old";

        result.push_back(Monkey(
            parseNumbers(block.at(1)),
            Operation {
                operation.at(4).at(0),
                self,
                self ? -1 : std::stoul(operation.at(5))
             },
            parseNumbers(block.at(3)).at(0),
            { parseNumbers(block.at(4)).at(0), parseNumbers(block.at(5)).at(0) }
        ));
    }

    return result;
}

/**
 *  Solves the 2022-12-11 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-11
 */
std::string Year2022::december11() const {
    if (exempt("11")) {
        return "";
    }
    std::cout << "DERPEPRPERP" << std::endl;
    std::cout << std::to_string(std::numeric_limits<double>::infinity()) << std::endl;

    std::vector<Monkey> monkeys = parseMonkeys();
    for (Monkey &monkey : monkeys) {
        echo(toStr(monkey.operate(123)));
    }
    echo("");

    for (size_t i = 0; i < 20; ++i) {
        for (Monkey &monkey : monkeys) {
            monkey.inspect(monkeys);
        }
        // for (Monkey &monkey : monkeys) {
        //     echo(monkey.itemz());
        // }
    }

    std::vector<size_t> results = {};
    for (Monkey &monkey : monkeys) {
        results.push_back(monkey.inspections());
    }
    const std::vector<size_t> winners = vectorHighest(results, 2);

    return std::to_string(winners.at(0) * winners.at(1));
}

