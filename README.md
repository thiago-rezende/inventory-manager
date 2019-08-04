# Ivy - Inventory Manager ![](https://img.shields.io/badge/W.I.P--red.svg)
[![All Contributors](https://img.shields.io/badge/all_contributors-2-orange.svg?style=flat-square)](#contributors)

![](https://img.shields.io/badge/build-passing-green.svg) ![](https://img.shields.io/badge/C++-17-orange.svg) ![](https://img.shields.io/badge/CMake-3.14.0-blue.svg) ![](https://img.shields.io/badge/Doxygen-1.8.15-9cf.svg) ![](https://img.shields.io/badge/Nana-1.7.1-turquoise.svg)

Assignment for the conclusion of the subject of Algorithms and Procedural Programming.

### Read the docs
>[Ivy - Inventory Manager Docs](https://thiago-rezende.github.io/inventory-manager/)

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
     make && make install                                   # Now run your preferred compiler
     ```

## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore -->
<table>
  <tr>
    <td align="center"><a href="https://novout.github.io/html/index.html"><img src="https://avatars3.githubusercontent.com/u/41403842?v=4" width="100px;" alt="Giovane Cardoso"/><br /><sub><b>Giovane Cardoso</b></sub></a><br /><a href="https://github.com/thiago-rezende/inventory-manager/commits?author=Novout" title="Code">💻</a> <a href="https://github.com/thiago-rezende/inventory-manager/commits?author=Novout" title="Tests">⚠️</a> <a href="#review-Novout" title="Reviewed Pull Requests">👀</a> <a href="#design-Novout" title="Design">🎨</a></td>
    <td align="center"><a href="http://thiago-rezende.github.io/"><img src="https://avatars2.githubusercontent.com/u/47676234?v=4" width="100px;" alt="Thiago Rezende"/><br /><sub><b>Thiago Rezende</b></sub></a><br /><a href="https://github.com/thiago-rezende/inventory-manager/commits?author=thiago-rezende" title="Code">💻</a> <a href="https://github.com/thiago-rezende/inventory-manager/commits?author=thiago-rezende" title="Documentation">📖</a> <a href="#maintenance-thiago-rezende" title="Maintenance">🚧</a> <a href="https://github.com/thiago-rezende/inventory-manager/issues?q=author%3Athiago-rezende" title="Bug reports">🐛</a> <a href="#ideas-thiago-rezende" title="Ideas, Planning, & Feedback">🤔</a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!
