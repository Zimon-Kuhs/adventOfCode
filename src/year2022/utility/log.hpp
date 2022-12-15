#ifndef __ADVENT_OF_CODE_LOG_HPP__
#define __ADVENT_OF_CODE_LOG_HPP__

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace adventOfCode {

void echo(const std::string &message);

template <typename T>
void echo(const std::vector<T> &lines);

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

template <typename T>
void echo(const std::set<T> &set) {
    std::stringstream string;
    std::string prefix = "";

    string << "{";
    for (const T &t : set) {
        string << prefix << t;
        prefix = ", ";
    }
    string << "}";

    echo(string.str());
}

template <typename T>
void echo(const std::stack<T> &stack) {
    std::stack<T> copy = std::stack<T>(stack);

    std::stringstream string;
    std::string prefix = "";

    while (!copy.empty()) {
        string << prefix << copy.top();
        copy.pop();
        prefix = "\n";
    }

    echo(string.str());
}

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

#define println() echo(std::string(__FILE__) + "#" + std::to_string(__LINE__));

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_LOG_HPP__
