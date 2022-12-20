#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "collections.hpp"
#include "files.hpp"
#include "strings.hpp"

#define toStr(x) std::to_string(x)

using namespace adventOfCode;

class CPU {
    public:
        CPU() : signals({}), changes({}), head(nullptr), data(1), cycle(0) {}

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
                signals.push_back(data * static_cast<int>(cycle));
            }

            std::pair<size_t, int> &change = changes.front();
            if (--change.first == 0) {
                data += change.second;
                changes.erase(changes.begin());
            }
        }

        int value() const {
            return data;
        }

    private:
        std::vector<int> signals;
        std::vector<std::pair<size_t, int>> changes;
        std::unique_ptr<std::pair<size_t, int>> head;
        int data;
        size_t cycle;
};

class CRT {
    public:
        CRT() : pixels({{}}), cycle(0) {}

        std::string string() const {
            std::stringstream result;
            for (const std::vector<char> &row : pixels) {
                for (const char &character : row) {
                    result << character;
                }
                result << std::endl;
            }
            return result.str();
        }

        void tick(const int &position) {
            if (cycle >= 40) {
                cycle = 0;
                pixels.push_back({});
            }

            pixels.back().push_back(
                std::abs(static_cast<int>(cycle++) - position) <= 1 ? '#' : '.'
            );
        }

    private:
        std::vector<std::vector<char>> pixels;
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

    CRT crt = CRT();
    while (cpu.busy()) {
        crt.tick(cpu.value());
        cpu.tick();
    }

    return crt.string();
}

