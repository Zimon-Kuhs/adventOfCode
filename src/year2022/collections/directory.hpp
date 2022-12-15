#ifndef __ADVENT_OF_CODE_DIRECTORY_HPP__
#define __ADVENT_OF_CODE_DIRECTORY_HPP__

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace adventOfCode {

class Directory {
    public:
        /**
         *  Initializes directory structure at root level.
         */
        Directory();

        /**
         *  Creates a subdirectory to the current one.
         *
         *  @param name The name of the subdirectory.
         */
        void create(const std::string &name);

        /**
         *  @param subDirectory A directory within the current one.
         *  @return             Pointer to the subdirectory requested.
         */
        std::shared_ptr<Directory> enter(const std::string &subDirectory) const;

        /**
         *  Creates a file in this directory.
         *
         *  @param name The name of the file.
         *  @param size The size of the file.
         */
        void file(const std::string &name, const size_t &size);

        /**
         *  @param subDirectory The directory to check for.
         *  @return             `true` if the current directory has a specified subdirectory.
         */
        bool has(const std::string &subDirectory) const;

        /**
         *  @return The total file size of the current directory.
         */
        size_t memory() const;

        /**
         *  @return A string specifying the current directory's path.
         */
        std::string path() const;

        /**
         *  @return The parent directory.
         */
        std::shared_ptr<Directory>  up() const;

    private:
        /**
         *  Initializes directory structure at root level.
         *
         *  @param name     The name of the directory.
         *  @param parent   The parent directory.
         */
        Directory(const std::string &name, const std::shared_ptr<Directory> parent);

        /**
         *  @return The name of the directory.
         */
        std::string name() const;

        const std::shared_ptr<Directory> me;
        const std::string dirName;
        const std::shared_ptr<Directory> parent;
        std::map<std::string, size_t> files;
        std::vector<std::shared_ptr<Directory>> directories;
};

}   // namespace adventOfCode

#endif  // __ADVENT_OF_CODE_DIRECTORY_HPP__
