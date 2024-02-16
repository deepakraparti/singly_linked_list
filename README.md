# Singly Linked List Library in C
[![.github/workflows/c-cpp.yml](https://github.com/deepakraparti/singly_linked_list/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/deepakraparti/singly_linked_list/actions/workflows/c-cpp.yml)

![Singly Linked List](https://github.com/deepakraparti/singly_linked_list/assets/20471967/d7fafcaa-4be0-4cff-a84f-06b8b7357fa1)

This repository contains a generic singly linked list C library capable of generating both static and dynamic libraries.

## Features

- **Insertion**:
  1. At the beginning
  2. At the end
  3. At any given position

- **Deletion**:
  1. Front node
  2. Last node
  3. Delete a node specified by the position

- **Manipulation**:
  - Reverse the list
  - Print the list
  - Search for specific data in the list using application-specific logic
  - Sort the list in ascending order using application-specific logic
  - Determine the length of the list
  - Check if the list is empty

# Directory Structure

This repository follows the following directory structure:
- `src/`: Contains the source code for the singly linked list library.
- `examples/`: Contains sample application source code.

## Getting Started

To utilize the library in your application, clone the repository:

```sh
 git clone git@github.com:deepakraparti/singly_linked_list.git
```

The sample application demonstrates the usage of the singly linked list library. You can explore it further in the [examples](examples/)  directory. Generate the sample application and libraries using make.

```sh
cd singly_linked_list
make
./bin/sample_application
```

The sample application will be placed in the bin directory, and the generated libraries can be found in the lib folder.

## Contribution

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## LICENSE
This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
