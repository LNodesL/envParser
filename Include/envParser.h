#ifndef ENVPARSER_H
#define ENVPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

class EnvParser {
private:
    std::map<std::string, std::string> data;

public:
    inline std::string trimWhitespace(const std::string& str) const  {
        std::size_t first = str.find_first_not_of(" \t");
        std::size_t last = str.find_last_not_of(" \t");
        if (first == std::string::npos) {
            return "";
        }
        return str.substr(first, last - first + 1);
    }

    inline std::string getValue(const std::string& key) const {
        auto keyIter = data.find(key);
        if (keyIter == data.end()) {
            throw std::runtime_error("Key not found: " + key);
        }
        return keyIter->second;
    }

    void parseFromFile(const std::string& filename);
    void setValue(const std::string& key, const std::string& value);
    void removeKey(const std::string& key);

    void saveToFile(const std::string& filename) const;
};

#endif
