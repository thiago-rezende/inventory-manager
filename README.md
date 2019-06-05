# Inventory Manager ![](https://img.shields.io/badge/W.I.P--red.svg)

![](https://img.shields.io/badge/build-failing-red.svg) ![](https://img.shields.io/badge/C++-17-orange.svg) ![](https://img.shields.io/badge/CMake-3.14.0-blue.svg) ![](https://img.shields.io/badge/Doxygen-1.8.15-9cf.svg)

Assignment for the conclusion of the subject of Algorithms and Procedural Programming.

## Project structure
 ```
    .
    ├── bin                      # Binaries will be here.
    ├── inventory-manager        # The main project.
    │   ├── include              # Headers folder.
    │   └── src                  # Source folder.
    |       └── CMakeLists.txt   # Project CMake build script.
    ├── vendor                   # Third-party packages will be here.
    └── CMakeLists.txt           # Main CMake build script.
```
### How to Use
 - First download and install CMake [here](https://cmake.org/download/), is highly recommended to read the documentation [here](https://cmake.org/cmake-tutorial/) to extend the project.
 - Execute the following commands
 
     ```
     git clone --recurse-submodules https://github.com/thiago-rezende/inventory-manager.git
     cd inventory-manager
     mkdir build
     cd build
     cmake .. -G"YOUR-GENERATOR-HERE"       # Read the CMake docs and select a generator
     make && sudo make install
     ```
