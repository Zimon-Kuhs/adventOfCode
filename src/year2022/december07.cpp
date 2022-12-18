#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "collections.hpp"
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

    const std::shared_ptr<Directory> root = std::make_shared<Directory>();
    std::shared_ptr<Directory> current = root;
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

    std::map<std::shared_ptr<Directory>, size_t> allDirs = root->findDirs();
    const size_t required = 30000000 - (70000000 - root->memory());

    size_t min = SIZE_MAX;
    std::shared_ptr<Directory> result = nullptr;
    std::vector<std::pair<std::shared_ptr<Directory>, size_t>> directories = {};
    for (const std::pair<std::shared_ptr<Directory>, size_t> dir : allDirs) {
        const size_t &fileSize = dir.second;
        if (dir.second > required && (result == nullptr || fileSize < min)) {
            result = dir.first;
            min = fileSize;
        }
    }

    return std::to_string(min);
}

