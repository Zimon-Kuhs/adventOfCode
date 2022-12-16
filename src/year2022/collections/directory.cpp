#include <algorithm>
#include <stack>
#include <stdexcept>

#include "directory.hpp"
#include "log.hpp"

#define ROOT_NAME ""

using namespace adventOfCode;

Directory::Directory() : Directory(ROOT_NAME, nullptr) {}

Directory::Directory(const std::string &name, const std::shared_ptr<Directory> parent) :
                     dirName(name), parent(parent), files({}), directories({}) {}

std::shared_ptr<Directory> Directory::create(const std::string &name) {
    if (has(name)) {
        throw std::runtime_error("Directory " + name + " already exists in " + dirName + ".");
    }
    std::shared_ptr<Directory> newDir = std::shared_ptr<Directory>(new Directory(name, me()));
    directories.push_back(newDir);
    return newDir;
}

std::shared_ptr<Directory> Directory::enter(const std::string &subDirectory) {
    if (subDirectory == "/") {
        return root();
    }
    if (subDirectory == "..") {
        return up();
    }
    if (subDirectory == ".") {
        return me();
    }

    std::shared_ptr<Directory> result = nullptr;
    for (const std::shared_ptr<Directory> &dir : directories) {
        if (dir->name() == subDirectory) {
            result = dir;
            break;
        }
    }

    if (result == nullptr) {
        result = create(subDirectory);
    }

    return result;
}

void Directory::file(const std::string &name, const size_t &size) {
    if (files.find(name) != files.end()) {
        throw std::runtime_error("File " + name + " already exists in " + dirName + ".");
    }
    files[name] = size;
}

bool Directory::has(const std::string &subDirectory) const {
    if (directories.empty()) {
        return false;
    }

    for (const std::shared_ptr<Directory> &dir : directories) {
        if (dir->name() == subDirectory) {
            return true;
        }
    }

    return false;
}

size_t Directory::memory(const size_t &maximum) const {
    size_t total = 0;
    for (const std::shared_ptr<Directory> subDirectory : directories) {
        total += subDirectory->memory(maximum);
    }

    for (const std::pair<std::string, size_t> &file : files) {
        const size_t &fileSize = file.second;
        if (fileSize >= maximum) {
            total += fileSize;
        }
    }

    return total;
}

std::vector<std::pair<std::shared_ptr<Directory>, size_t>> Directory::findDirs(const size_t &maximum) {
    std::vector<std::pair<std::shared_ptr<Directory>, size_t>> result = {};
    for (const std::shared_ptr<Directory> subDirectory : directories) {
        for (const std::pair<std::shared_ptr<Directory>, size_t> &found : subDirectory->findDirs(maximum)) {
            result.push_back(found);
        }
    }

    const size_t bytes = memory(0);
    if (memory(0) < maximum) {
        result.push_back({ me(), bytes });
    }

    return result;
}

std::string Directory::name() const {
    return dirName;
}

std::shared_ptr<Directory> Directory::me() {
    return shared_from_this();
}

std::string Directory::path() const {
    std::stack<std::string> fullPath = {};
    std::shared_ptr<Directory> dir = parent;

    while (dir != nullptr) {
        fullPath.push(dir->name());
        dir = dir->up();
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

std::shared_ptr<Directory> Directory::root() {
    std::shared_ptr<Directory> dir = me();

    while (dir->parent != nullptr) {
        dir = dir->parent;
    }
    return dir;
}

std::shared_ptr<Directory> Directory::up() const {
    return parent;
}
