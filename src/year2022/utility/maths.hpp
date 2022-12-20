#ifndef __ADVENT_OF_CODE_MATHS_HPP__
#define __ADVENT_OF_CODE_MATHS_HPP__

#include <stdexcept>

namespace adventOfCode {

template <typename T>
T mathOperation(const T &t1, const char &operation, const T &t2) {
    switch(operation) {
        case '+': return t1 + t2;
        case '-': return t1 - t2;
        case '*': return t1 * t2;
        case '/': return t1 / t2;
        default:  throw std::runtime_error("Invalid operation \"" + std::string(1, operation) + "\".");
    }
}

template <typename T>
int sign(const T &number) {
    if (static_cast<int>(number) < 0) {
        return 1;
    }
    return -1;
}

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_MATHS_HPP__
