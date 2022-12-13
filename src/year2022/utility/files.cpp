#include <fstream>
#include <iterator>
#include <string>

#include "files.hpp"
#include "log.hpp"
#include "strings.hpp"

using namespace adventOfCode;

std::filesystem::path checkPath(const std::filesystem::path &file, const bool &expectFile = false) {
    if (!std::filesystem::exists(file)) {
        throw std::runtime_error("Path " + file.string() + " does not exist!");
    }

    const bool isFile = std::filesystem::is_regular_file(file);
    if (expectFile != isFile) {
        const std::string expected = expectFile ? "file" : "directory";
        const std::string actual = isFile ? "file" : "directory";
        throw std::runtime_error("Expected " + file.string() + " to be a " + expected + ", was " + actual + ".");
    }

    return file;
}

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
    for (const std::string &line : fileAsLines(checkPath(file, true), keepEmpty)) {
        std::istringstream buffer(line);
        std::vector<std::string> parts((std::istream_iterator<std::string>(buffer)),
                                        std::istream_iterator<std::string>());
        result.push_back(parts);
    }

    return result;
}
