#ifndef __ADVENT_OF_CODE_LOG_HPP__
#define __ADVENT_OF_CODE_LOG_HPP__

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace adventOfCode {

void echo(const std::string &message);

template <typename T>
void echo(const std::vector<T> &lines) {
    std::stringstream result;
    result << "{ ";
    std::string prefix = "";
    for (const T &element : lines) {
        result << prefix << element;
        prefix = ", ";
    }
    result << " }";
    echo(result.str());
}

template <typename K, typename V>
void echo(const std::map<K, V> &map) {
    const std::string indent = "    ";
    std::vector<std::string> lines = { "{" };

    for (const std::pair<K, V> &entry: map) {
        std::stringstream line = indent;
        line << entry.first << " : " << entry.second;
        lines.push_back(line.str());
    }
    lines.push_back("}");

    for (const std::string &line : lines) {
        echo(line);
    }
}

#define println() echo(std::string(__FILE__) + "#" + std::to_string(__LINE__));

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_LOG_HPP__
