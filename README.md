# Lightweight C++ Env Parser

EnvParser is a simple C++ class for parsing .env files and managing environment variables.

## Features

- Parses .env files and stores key-value pairs.
- Supports setting, removing, and retrieving key-value pairs.
- Saves changes to .env files.

## Usage

### 1. Include the `envParser.h` header file in your project.

```cpp
#include "envParser.h"
```

### 2. Create an instance of `EnvParser`.

```cpp
EnvParser parser;
```

### 3. Parse a .env file.

```cpp
parser.parseFromFile("example.env");
```

### 4. Get the value of a key.

```cpp
std::string value = parser.getValue("KEY_NAME");
```

### 5. Set a new key-value pair.

```cpp
parser.setValue("NEW_KEY", "new_value");
```

### 6. Remove a key.

```cpp
parser.removeKey("KEY_NAME");
```

### 7. Save changes to a .env file.

```cpp
parser.saveToFile("updated_env.env");
```

## Example

Here's a simple example of using EnvParser:

```cpp
#include "envParser.h"
#include <iostream>

int main() {
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
        return 1;
    }
    return 0;
}
```
