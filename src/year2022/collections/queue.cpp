#include <stdexcept>
#include <string>

#include "queue.hpp"

using namespace adventOfCode;

template <typename T>
Queue<T>::Queue() : Queue<T>({}, 0) {}

template <typename T>
Queue<T>::Queue(const std::vector<T> &intialElements, const size_t maxLength) :
                elements(intialElements), maxLength(maxLength == 0 ? SIZE_MAX : maxLength) {}

template <typename T>
void Queue<T>::add(const T &element) {
    while (elements.size() >= maxLength) {
        elements.pop_back();
    }
    elements.insert(elements.begin(), element);
}

template <typename T>
T Queue<T>::at(const size_t &index) const {
    if (index >= elements.size()) {
        throw std::runtime_error(std::to_string(index) + " is out of bounds for queue.");
    }
    return elements.at(index);
}

template <typename T>
T Queue<T>::end() const {
    return elements.end();
}

template <typename T>
size_t Queue<T>::maxSize() const {
    return maxLength;
}

template <typename T>
size_t Queue<T>::size() const {
    return elements.size();
}

template <typename T>
T Queue<T>::start() const {
    return elements.begin();
}
