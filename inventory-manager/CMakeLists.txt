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
)


target_link_libraries(inventory-manager PUBLIC)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
