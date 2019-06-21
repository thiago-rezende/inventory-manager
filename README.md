# Ivy - Inventory Manager ![](https://img.shields.io/badge/W.I.P--red.svg)

![](https://img.shields.io/badge/build-passing-green.svg) ![](https://img.shields.io/badge/C++-17-orange.svg) ![](https://img.shields.io/badge/CMake-3.14.0-blue.svg) ![](https://img.shields.io/badge/Doxygen-1.8.15-9cf.svg) ![](https://img.shields.io/badge/Nana-1.7.1-turquoise.svg)

Assignment for the conclusion of the subject of Algorithms and Procedural Programming.

## Project structure
 ```
    .
    ├── bin                      # Binaries will be here.
    ├── lib                      # Libraries will be here.
    ├── docs                     # The documentation will be here.
    ├── src                      # Source folder.
    |   └── CMakeLists.txt       # Project CMake build script.
    ├── vendor                   # Third-party packages will be here.
    └── CMakeLists.txt           # Main CMake build script.
```
### How to Use
 - First download and install CMake [here](https://cmake.org/download/), is highly recommended to read the documentation [here](https://cmake.org/cmake-tutorial/) to extend the project.
 - Execute the following commands
 > NOTE: When compiling for the first time may take some time due to nano library compilation, do not worry, it's not stuck.
 
     ```
     git clone --recursive https://github.com/thiago-rezende/inventory-manager.git
     cd inventory-manager
     mkdir build
     cd build
     cmake .. -G"GENERATOR-HERE" -DBUILD_SHARED_LIBS=ON     # Read the CMake docs and select a generator
     make && make install
     ```
