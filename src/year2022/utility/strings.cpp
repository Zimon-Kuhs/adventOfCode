#include <sstream>

#include "strings.hpp"

using namespace adventOfCode;

std::vector<std::string> adventOfCode::splitString(const std::string &string, const char &delimiter) {
    std::vector<std::string> tokens;
    std::stringstream mySstream(string);
    std::string token;

    while(std::getline( mySstream, token, delimiter ) ) {
        tokens.push_back(token);
    }

    return tokens;
}
