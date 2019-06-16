project(inventory-manager)

add_executable(inventory-manager ${SOURCES})

target_sources(inventory-manager
PUBLIC 
    "src/main.cpp"
    "src/ivy/ivy_manager/IvyManager.hpp"
    "src/ivy/ivy_manager/IvyManager.cpp"
    "src/ivy/interface/InterfaceCLI.hpp"
    "src/ivy/interface/InterfaceCLI.cpp"
    "src/ivy/produto/Produto.hpp"
    "src/ivy/produto/Produto.cpp"
    "src/ivy/vetor/Vetor.hpp"
    "src/ivy/vetor/Vetor.cpp"
)

target_include_directories(inventory-manager
PUBLIC 
    "include"
    "src/ivy"
    "src/ivy/ivy_manager"
    "src/ivy/produto"
    "src/ivy/vetor"
)


target_link_libraries(inventory-manager PUBLIC)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
