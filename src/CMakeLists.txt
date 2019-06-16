project(ivy-manager)

add_executable(ivy-manager ${SOURCES})
set_property(TARGET ivy-manager PROPERTY CXX_STANDARD 17)

target_sources(ivy-manager
PUBLIC 
    "main.cpp"
    "ivy/ivy_manager/IvyManager.hpp"
    "ivy/ivy_manager/IvyManager.cpp"
    "ivy/interface/InterfaceCLI.hpp"
    "ivy/interface/InterfaceCLI.cpp"
    "ivy/produto/Produto.hpp"
    "ivy/produto/Produto.cpp"
    "ivy/vetor/Vetor.hpp"
    "ivy/vetor/Vetor.cpp"
)

target_include_directories(ivy-manager
PUBLIC 
    "include"
    "ivy"
    "ivy/ivy_manager"
    "ivy/produto"
    "ivy/vetor"
)


install(TARGETS ivy-manager RUNTIME DESTINATION bin)
