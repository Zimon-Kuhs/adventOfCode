#include <stack>

#include "directory.hpp"

#define ROOT_NAME ""

using namespace adventOfCode;

Directory::Directory() : Directory(ROOT_NAME, nullptr) {}

Directory::Directory(const std::string &name, const std::shared_ptr<Directory> parent) :
                     me(std::make_shared<Directory>(this)), dirName(name), parent(parent), files({}), directories({}) {

}

void Directory::file(const std::string &name, const size_t &size) {
    if (files.contains(name)) {
        throw std::runtime_error("File " + name + " already exists in " + dirName + ".");
    }
    files[name] = size;
}

void Directory::create(const std::string &name) {
    if (has(name)) {
        throw std::runtime_error("Directory " + name + " already exists in " + dirName + ".");
    }
    directories.push_back(std::make_shared<Directory>(name, me));
}

std::shared_ptr<Directory> Directory::enter(const std::string &subDirectory) const {
    for (const std::shared_ptr<Directory> dir : directories) {
        if (dir->name() == subDirectory) {
            return dir;
        }
    }
    throw std::runtime_error("Directory " + subDirectory + " doesn't exist in " + dirName + ".");
}

bool Directory::has(const std::string &subDirectory) const {
    return std::find(directories.begin(), directories.end(), name) != directories.end();
}

size_t Directory::memory() const {
    size_t total = 0;
    for (const std::shared_ptr<Directory> subDirectory : directories) {
        total += subDirectory->memory();
    }
    for (const std::pair<std::string, size_t> &file : files) {
        total += file.second;
    }
    return total;
}

std::string Directory::name() const {
    return dirName;
}

std::string Directory::path() const {
    std::stack<std::string> fullPath = {};
    std::shared_ptr<Directory> dir = me;

    while (dir != nullptr) {
        fullPath.push(dir->name());
        dir = dir->parent;
    }

    std::string result = "";
    std::string separator = "";
    while (!fullPath.empty()) {
        result += fullPath.top();
        fullPath.pop();
        separator = "/";
    }
    return result;
}

std::shared_ptr<Directory> Directory::up() const {
    return parent;
}
