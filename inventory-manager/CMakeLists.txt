project(inventory-manager)

add_executable(inventory-manager ${SOURCES})

target_sources(inventory-manager
PUBLIC 
    "src/main.cpp"
    "src/ivy/ivy.hpp"
    "src/ivy/ivy.cpp"
    "src/ivy/produto/Produto.hpp"
    "src/ivy/produto/Produto.cpp"
    "src/ivy/vetor/Vetor.hpp"
    "src/ivy/vetor/Vetor.cpp"
)

target_include_directories(inventory-manager
PUBLIC 
    "include"
    "src/ivy"
    "src/ivy/produto"
    "src/ivy/vetor"
)


target_link_libraries(inventory-manager PUBLIC)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
