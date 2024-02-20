#include "../include/envParser.h"
#include <iostream>

int main() {
    // Create an instance of EnvParser
    EnvParser parser;

    try {
        // Parse the .env file
        parser.parseFromFile("demo.env");

        // Get and print the value of a key
        std::cout << "Value of KEY1: " << parser.getValue("KEY1") << std::endl;

        // Set a new key-value pair
        parser.setValue("NEW_KEY", "new_value");

        // Save the changes to a new file
        parser.saveToFile("updated_env.env");

        // Remove a key
        parser.removeKey("KEY2");

        // Save the updated file
        parser.saveToFile("updated_env_removed_key.env");

        std::cout << "Test completed successfully." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1; // indicate failure
    }

    return 0; // indicate success
}
