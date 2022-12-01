#ifndef __ADVENT_OF_CODE_COLLECTIONS_HPP__
#define __ADVENT_OF_CODE_COLLECTIONS_HPP__

#include <vector>

namespace adventOfCode {

/**
 *  @param vector   The vector which elements to parse.
 *  @return         The smallest element in `vector`.
 */
template <typename N>
N vectorMin(const std::vector<N> &vector) {
    N minimum = vector.at(0);
    for (const N &element : vector) {
        minimum = std::min(minimum, element);
    }
    return minimum;
}

/**
 *  @param vector   The vector which elements to sum.
 *  @return         The sum of all elements in `vector`.
 */
template <typename N>
N vectorSum(const std::vector<N> &vector) {
    long long total = 0;
    for (const N &element : vector) {
        total += element;
    }
    return total;
}

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_COLLECTIONS_HPP__
