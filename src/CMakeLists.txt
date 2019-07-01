project(ivy-manager)

add_executable(ivy-manager ${SOURCES})
set_property(TARGET ivy-manager PROPERTY CXX_STANDARD 17)
target_compile_definitions(ivy-manager PRIVATE -DIVY_DEBUG)

target_sources(ivy-manager
PUBLIC 
    "main.cpp"
    "ivy/log/IvyLog.cpp"
    "ivy/ivy_manager/IvyManager.cpp"
    "ivy/interface/InterfaceCLI.cpp"
    "ivy/interface/InterfaceGUI.cpp"
    "ivy/produto/Produto.cpp"
    "ivy/vetor/Vetor.cpp"
    # resources
    "CMakeSetup.rc"
    # locadora
    "ivy/locadora/jogo/Jogo.cpp"
    "ivy/locadora/Locadora.cpp"
    "ivy/locadora/LocadoraCLI.cpp"
)

target_include_directories(ivy-manager
PUBLIC 
    ${NANA_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/vendor/cli/include/
    ${CMAKE_SOURCE_DIR}/vendor/spdlog/include/
    "ivy"
    "ivy/interface"
    "ivy/log"
    "ivy/ivy_manager"
    "ivy/produto"
    "ivy/vetor"
    "ivy/locadora"
)

target_link_libraries(ivy-manager PRIVATE nana)

add_custom_target(copy_resources ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/res ${CMAKE_BINARY_DIR}/bin/res
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/res ${CMAKE_INSTALL_PREFIX}/bin/res
    DEPENDS ivy-manager)

install(TARGETS ivy-manager RUNTIME DESTINATION bin)
