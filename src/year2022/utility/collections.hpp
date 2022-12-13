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
 *  Splits a vector into a number of parts, biased towards leftmost segments.
 *  <p>
 *  E.g. divideVector({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3) will yield { { 1, 2, 3, 4 }, { 5, 6, 7 }, { 8, 9, 10 } };
 *
 *  @param string   The vector to split.
 *  @param parts    How many segments to split the vector into.
 *  @return         Vector containing `parts` subvector segments.
 */
template <typename T>
std::vector<std::vector<T>> divideVector(const std::vector<T> &vector, const size_t &parts) {
    const size_t &size = vector.length();

    if (parts > size) {
        throw std::runtime_error("Can't divide a vector of length " + std::to_string(size) +
                                 " into " + std::to_string(parts) + " parts.");
    }

    std::vector<size_t> lengths = std::vector(parts, size / parts);
    for (size_t i = 0; i < size % parts; ++i) {
        lengths.at(i) += 1;
    }

    std::vector<std::string> result = {};
    size_t start = vector.begin();

    for (const size_t &length : lengths) {
        result.push_back(std::vector<T>(start, start + length));
        start += length;
    }

    return result;
}

/**
 *  Creates subvectors of a specified size from a vector.
 *
 *  @param vector       The vector of elements to create groups from.
 *  @param groupSize    The size of the group(s).
 *  @return             A vector of vectors, the latter of size `size`.
 */
template <typename T>
std::vector<std::vector<T>> subVectors(const std::vector<T> &vector, const size_t &groupSize) {
    const size_t &size = vector.size();

    if (groupSize > size) {
        throw std::runtime_error("Can't divide a vector of length " + std::to_string(size) +
                                 " into groups of size " + std::to_string(groupSize) + ".");
    }

    const size_t groupAmount = vector.size() / groupSize;

    std::vector<std::vector<T>> result = {};
    typename std::vector<T>::const_iterator start = vector.begin();

    for (size_t i = 0; i < groupAmount; ++i) {
        result.push_back(std::vector<T>(start, start + groupSize));
        start += groupSize;
    }

    if (start != vector.end()) {
        result.push_back(std::vector<T>(start, vector.end()));
    }

    return result;
}

/**
 *  @param elements The elements to choose from.
 *  @param amount   The amount of elements to choose.
 *  @return         The `amount` highest number in `elements`.
 */
template <typename N>
std::vector<N> vectorHighest(const std::vector<N> elements, const size_t &amount = 1) {

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
