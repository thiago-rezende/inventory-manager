project(inventory-manager)

add_executable(inventory-manager ${SOURCES})

target_sources(inventory-manager
PUBLIC 
    "src/main.cpp"
)

target_include_directories(inventory-manager
PUBLIC 
    "include"
    ${YAML_CPP_SOURCE_DIR}/include
)

target_link_libraries(inventory-manager
PUBLIC 
    yaml-cpp
)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
