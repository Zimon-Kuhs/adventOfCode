#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "directory.hpp"
#include "files.hpp"
#include "strings.hpp"

using namespace adventOfCode;

/**
 *  Solves the 2022-12-07 problem.

 *  @author Zimon Kuhs
 *  @date   2022-12-07
 */
std::string Year2022::december07() const {
    if (exempt("07")) {
        return "";
    }

    std::shared_ptr<Directory> current = std::make_shared<Directory>();
    std::vector<std::string> lines = fileAsLines(std::filesystem::path("input/07.txt"));

    for (size_t i = 0; i < lines.size(); ++i) {
        std::string &line = lines.at(i);
        const std::vector<std::string> parts = splitString(line, ' ');

        if (parts.at(0) == "$") {
            if (parts.at(1) == "cd") {
                current = current->enter(parts.at(2));
            } else {
                continue;
            }
        } else if (parts.at(0) == "dir") {
            current->create(parts.at(1));
        } else {
            current->file(parts.at(1), std::stoul(parts.at(0)));
        }
    }

    size_t total = 0;
    for (const std::pair<std::shared_ptr<Directory>, size_t> &dir : current->root()->findDirs(100000)) {
        total += dir.second;
    }

    return std::to_string(total);
}

