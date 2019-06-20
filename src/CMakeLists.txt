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
    ${NANA_INCLUDE_DIR}
    "ivy"
    "ivy/ivy_manager"
    "ivy/produto"
    "ivy/vetor"
)

target_link_libraries(ivy-manager PRIVATE nana)

install(TARGETS ivy-manager RUNTIME DESTINATION bin)
