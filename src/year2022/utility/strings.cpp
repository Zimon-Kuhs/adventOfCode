#include <sstream>

#include "log.hpp"
#include "strings.hpp"

using namespace adventOfCode;

std::vector<std::string> adventOfCode::divideString(const std::string &string, const size_t &parts) {
    const size_t &size = string.length();

    if (parts > size) {
        throw std::runtime_error("Can't divide a string of length " + std::to_string(size) +
                                 " into " + std::to_string(parts) + " parts.");
    }

    std::vector<size_t> lengths = std::vector(parts, size / parts);
    for (size_t i = 0; i < size % parts; ++i) {
        lengths.at(i) += 1;
    }

    std::vector<std::string> result = {};
    size_t start = 0;

    for (const size_t &length : lengths) {
        result.push_back(string.substr(start, length));
        start += length;
    }

    return result;
}

std::vector<std::string> adventOfCode::splitString(const std::string &string, const char &delimiter) {
    std::vector<std::string> tokens;
    std::stringstream mySstream(string);
    std::string token;

    while(std::getline( mySstream, token, delimiter ) ) {
        tokens.push_back(token);
    }

    return tokens;
}
