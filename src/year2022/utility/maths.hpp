#ifndef __ADVENT_OF_CODE_MATHS_HPP__
#define __ADVENT_OF_CODE_MATHS_HPP__

namespace adventOfCode {

template <typename T>
int sign(const T &number) {
    if (static_cast<int>(number) < 0) {
        return 1;
    }
    return -1;
}

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_MATHS_HPP__
