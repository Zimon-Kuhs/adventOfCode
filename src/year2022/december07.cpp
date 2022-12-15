#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include "year2022.hpp"
#include "directory.hpp"
#include "files.hpp"

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

    std::unique_ptr<Directory> current = std::make_unique<Directory>();

    for (const std::string &line : fileAsLines(std::filesystem::path("input/07.txt"))) {
        if (line.at(0) == '$') {
            const std::string &cmd = line.substr(2, 2);
            if (cmd == "cd") {
                // CD.
            } else if (cmd == "ls") {
                // Add files, create subDirectories.
            } else {
                throw std::runtime_error("Parsed invalid command: " + cmd);
            }
        }
    }

    // TODO: Also add memory size filtering.
    return "TBI";
}

