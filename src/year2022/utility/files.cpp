#include <fstream>

#include "files.hpp"

using namespace adventOfCode;

std::vector<std::string> adventOfCode::fileAsLines(const std::filesystem::path &file, const bool &keepEmpty) {
    std::ifstream fileStream(file.c_str());
    std::vector<std::string> result = {};

    if (!fileStream.is_open()) {
        throw std::runtime_error("Could not read " + file.string());
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        if (keepEmpty || !line.empty()) {
            result.push_back(line);
        }
    }

    fileStream.close();
    return result;
}
