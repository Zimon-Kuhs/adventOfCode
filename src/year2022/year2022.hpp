#ifndef __ADVENT_OF_CODE_DECEMBER_2022_HPP__
#define __ADVENT_OF_CODE_DECEMBER_2022_HPP__

#include <algorithm>
#include <string>
#include <vector>

#include "log.hpp"

namespace adventOfCode {

/**
 * Base test class.
*/
class Year2022 final {
    public:
        Year2022 (const std::vector<std::string> &selection) : tests({}) {
            const bool &all = selection.empty();
            for (size_t i = 1; i < 26; ++i) {
                const std::string &number = (i >= 10 ? "" : "0" ) + std::to_string(i);
                if (all || std::find(selection.begin(), selection.end(), number) != selection.end()) {
                    tests.push_back(number);
                }
            }
        }

        std::string december01() const;
        std::string december02() const;
        std::string december03() const;
        std::string december04() const;
        std::string december05() const;
        std::string december06() const;
        std::string december07() const;
        std::string december08() const;
        std::string december09() const;
        std::string december10() const;
        std::string december11() const;
        std::string december12() const;
        std::string december13() const;
        std::string december14() const;
        std::string december15() const;
        std::string december16() const;
        std::string december17() const;
        std::string december18() const;
        std::string december19() const;
        std::string december20() const;
        std::string december21() const;
        std::string december22() const;
        std::string december23() const;
        std::string december24() const;
        std::string december25() const;

    protected:
        bool exempt(const std::string &number) const {
            return std::find(tests.begin(), tests.end(), number) == tests.end();
        }

    private:
            std::vector<std::string> tests;
};

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_DECEMBER_2022_HPP__
