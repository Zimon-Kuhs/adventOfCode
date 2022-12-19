#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "collections.hpp"
#include "files.hpp"
#include "strings.hpp"

#define str(x) std::to_string(x)

using namespace adventOfCode;

class CPU {
    public:
        CPU() : signals({}), changes({}), head(nullptr), value(1), cycle(0) {}

        void addX(const int &value) {
            changes.push_back({ 2, value });
        }

        bool busy() const {
            return !changes.empty();
        }

        void noop() {
            changes.push_back({ 1, 0 });
        }

        std::vector<int> strengths() const {
            return std::vector<int>(signals);
        }

        void tick() {
            if (++cycle % 40 == 20) {
                signals.push_back(value * static_cast<int>(cycle));
            }

            std::pair<size_t, int> &change = changes.front();
            if (--change.first == 0) {
                value += change.second;
                changes.erase(changes.begin());
            }
        }

    private:
        std::vector<int> signals;
        std::vector<std::pair<size_t, int>> changes;
        std::unique_ptr<std::pair<size_t, int>> head;
        int value;
        size_t cycle;
};

/**
 *  Solves the 2022-12-10 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-10
 */
std::string Year2022::december10() const {
    if (exempt("10")) {
        return "";
    }

    CPU cpu = CPU();
    for (const std::string &line : fileAsLines(std::filesystem::path("input/10.txt"))) {
        const std::vector<std::string> parts = splitString(line, ' ');
        if (parts.size() == 1) {
            cpu.noop();
        } else {
            cpu.addX(std::stoi(parts.at(1)));
        }
    }

    while (cpu.busy()) {
        cpu.tick();
    }

    return std::to_string(vectorSum(cpu.strengths()));
}

