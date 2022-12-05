#include <fstream>
#include <string>

#include "files.hpp"
#include "strings.hpp"

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

std::vector<std::vector<std::string>> adventOfCode::fileAsMatrix(const std::filesystem::path &file,
                                                                 const bool &keepEmpty) {

    std::vector<std::vector<std::string>> result = {};
    for (const std::string &line : fileAsLines(file, keepEmpty)) {
        std::istringstream buffer(line);
        std::vector<std::string> parts((std::istream_iterator<std::string>(buffer)),
                                        std::istream_iterator<std::string>());
        result.push_back(parts);
    }

    return result;
}
