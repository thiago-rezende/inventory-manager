project(inventory-manager)

add_executable(inventory-manager ${SOURCES})

target_sources(inventory-manager
PUBLIC 
    "src/main.cpp"
    "src/ivy/ivy.cpp"
    "src/ivy/produto/Produto.cpp"
)

target_include_directories(inventory-manager
PUBLIC 
    "include"
#    ${YAML_CPP_SOURCE_DIR}/include
)

# YAML_CPP lib
#target_link_libraries(inventory-manager
#PUBLIC 
#    yaml-cpp
#)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
