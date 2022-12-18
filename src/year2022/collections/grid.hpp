#ifndef __ADVENT_OF_CODE_GRID_HPP__
#define __ADVENT_OF_CODE_GRID_HPP__

#include <stdexcept>
#include <string>
#include <vector>

#include "log.hpp"

namespace adventOfCode {

/**
 *  Represents a grid-system.
 */
template <typename T>
class Grid {
    public:

        /**
         *  Creates a square grid.
         *
         *  @param length The row and column length.
         */
        Grid(const size_t &length) : Grid(length, length) {}

        /**
         *  Creates a grid.
         *
         *  @param height The row length.
         *  @param width  The column length.
         */
        Grid(const size_t &height, const size_t &width) :
                        Grid(std::vector<std::vector<T>>(height, std::vector<T>(width, T()))) {}

        /**
         *  Creates a grid.
         *
         *  @param elements The elements to insert into the grid.
         */
        Grid(const std::vector<std::vector<T>> &elements) : grid({}),
                                                            pointer({ 0, 0 }),
                                                            gridHeight(elements.size()),
                                                            gridWidth(elements.at(0).size()) {

            for (const std::vector<T> &row : elements) {
                if (row.size() != gridWidth) {
                    throw std::runtime_error("Can not create a jagged grid!");
                }
                grid.push_back(std::vector<T>(row));
            }
        }

        /**
         *  @param row      The row position of the element.
         *  @param column   The column position of the element.
         *  @return         The element at the specified position.
         */
        T at(const size_t &row, const size_t &column) const {
            checkIndex(row, column);
            return grid.at(row).at(column);
        }

        /**
         *  @return The element at the current position.
         */
        T current() const {
            return at(pointer.first, pointer.second);
        }

        /**
         *  @param down     Set to `true` if the vertical movement should be down, `false` if it should be up.
         *  @param right    Set to `true` if the horizontal movement should be right, `false` if it should be left.
         *  @return         If a diagonal movement was possible.
         */
        bool diagonally(const bool &down, const bool &right) {
            return shiftPointer(down ? 1 : -1, right ? 1 : -1);
        }

        /**
         *  @return `true` if a step downward was possible.
         */
        bool down() {
            return shiftPointer(1, 0);
        }

        /**
         *  @return The amount of rows in the grid.
         */
        size_t height() const {
            return gridHeight;
        }

        /**
         *  @param row      The row position to set.
         *  @param column   The column position to set.
         *  @param value    The value to set the position to.
         */
        void insert(const size_t &row, const size_t &column, const T &value) {
            checkIndex(row, column);
            grid.at(row).at(column) = value;
        }

        /**
         *  @return `true` if a step to the left was possible.
         */
        bool left() {
            return shiftPointer(0, -1);
        }

        /**
         *  @param dy   The vertical movement.
         *  @param dx   The horizontal movement.
         *  @return     `true` if the movement was possible.
         */
        bool move(const int &dy, const int &dx) {
            return shiftPointer(dy, dx);
        }

        /**
         *  @return `true` if a step to the right was possible.
         */
        bool right() {
            return shiftPointer(0, 1);
        }

        /**
         *  Move the pointer to a specific position.
         *
         *  @param row      The row to move to.
         *  @param column   The row to move to.
         */
        void set(const size_t &row, const size_t &column) {
            checkIndex(row, column);
            pointer.first = row;
            pointer.second = column;
        }

        /**
         *  @return `true` if the dimensions are n x n.
         */
        bool square() const {
            return height() == width();
        }

        /**
         *  @return `true` if a step upward was possible.
         */
        bool up() {
            return shiftPointer(-1, 0);
        }

        /**
         *  @return The amount of columns in the grid.
         */
        size_t width() const {
            return gridWidth;
        }

    private:
        /**
         *  Checks the specified coordinates and throws an exception if they're out of bounds.
         */
        void checkIndex(const size_t &row, const size_t &column) const {
            if (row >= gridHeight || column >= gridWidth) {
                throw std::runtime_error("Invalid index " + indexString(row, column) + ".");
            }
        }

        /**
         *  Short-hand for an index string.
         *
         *  @param row      The row index.
         *  @param column   The column index.
         *  @param          "[$row, $column]"
         */
        static std::string indexString(const size_t &row, const size_t &column) {
            return "[" + std::to_string(row) + ", " + std::to_string(column) + "]";
        }

        /**
         *  Attempts to move the pointer a certain distance from its current position.
         *
         *  @param dy   The vertical movement to attempt.
         *  @param dx   The horizontal movement to attempt.
         *  @return     `true` if the movement was possible.
         */
        bool shiftPointer(const int &dy, const int &dx) {
            const int &y = static_cast<int>(pointer.first);
            const int &x = static_cast<int>(pointer.second);

            if ((y + dy < 0 || y + dy >= static_cast<int>(gridHeight)) ||
                (x + dx < 0 || x + dx >= static_cast<int>(gridWidth))) {

                return false;
            }

            pointer.first = static_cast<size_t>(y + dy);
            pointer.second = static_cast<size_t>(x + dx);
            return true;
        }

        std::vector<std::vector<T>> grid;
        std::pair<size_t, size_t> pointer;

        const size_t gridHeight;
        const size_t gridWidth;

};

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_GRID_HPP__
