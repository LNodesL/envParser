#include "envParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

void EnvParser::parseFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;

    while (std::getline(file, line)) {
        // skip empty lines and comments
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }

        // parse key-value pairs
        auto delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) {
            throw std::runtime_error("Invalid line format: " + line);
        }

        // extract key and value
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // trim whitespace around key and value
        key = trimWhitespace(key);
        value = trimWhitespace(value);

        // add key-value pair to the map
        data[key] = value;
    }
}

void EnvParser::setValue(const std::string& key, const std::string& value) {
    // trim leading and trailing whitespace from the key
    std::string trimmedKey = trimWhitespace(key);

    // set or update the value for the key
    data[trimmedKey] = value;
}

void EnvParser::removeKey(const std::string& key) {
    // remove the key if it exists
    data.erase(key);
}

void EnvParser::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    for (const auto& keyValue : data) {
        // trim leading and trailing whitespace from the key and value
        std::string trimmedKey = trimWhitespace(keyValue.first);
        std::string trimmedValue = trimWhitespace(keyValue.second);

        file << trimmedKey << "=" << trimmedValue << std::endl;
    }
}
