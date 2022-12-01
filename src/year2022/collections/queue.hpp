#ifndef __ADVENT_OF_CODE_QUEUE_HPP__
#define __ADVENT_OF_CODE_QUEUE_HPP__

#include <limits>
#include <vector>

namespace adventOfCode {

template <typename T>
class Queue {
    public:
        /**
         *  Initializes an empty queue without max length.
         */
        Queue();

        /**
         *  @param initialElements  The initial elements of the queue.
         *  @param maxLength        The length of the queue.
         */
        Queue(const std::vector<T> &intialElements, const size_t maxLength = SIZE_MAX);

        /**
         *  @param element  The element to add to the queue.
         */
        void add(const T &element);

        /**
         *  @param index    The index of the element to get.
         *  @return         The element at index `index`.
         */
        T at(const size_t &index) const;

        /**
         *  @return The element inserted into the queue first.
         */
        T end() const;

        /**
         *  @return The amount of elements the queue is allowed to have.
         */
        size_t maxSize() const;

        /**
         *  @return The number of elements in the queue.
         */
        size_t size() const;

        /**
         *  @return The element inserted into the queue last.
         */
        T start() const;

        private:
            std::vector<T> elements;
            const size_t maxLength;
};

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_QUEUE_HPP__
