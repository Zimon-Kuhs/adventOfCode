#ifndef __ADVENT_OF_CODE_COLLECTIONS_HPP__
#define __ADVENT_OF_CODE_COLLECTIONS_HPP__

#include <algorithm>
#include <stdexcept>
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
 *  @param elements The elements to choose from.
 *  @param amount   The amount of elements to choose.
 *  @return         The `amount` highest number in `elements`.
 */
template <typename N>
std::vector<N> vectorHighest(const std::vector<N> elements, const size_t &amount) {

    const size_t numberOfElements = elements.size();
    if (amount > numberOfElements) {
        throw std::runtime_error("Amount too high: " + std::to_string(amount));
    }

    std::vector<N> highest = std::vector<N>(elements);
    if (amount == numberOfElements) {
        return highest;
    }

    std::sort(highest.rbegin(), highest.rend());
    highest.erase(highest.begin() + amount, highest.end());

    return highest;
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
