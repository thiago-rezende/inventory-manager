project(inventory-manager)

add_executable(inventory-manager ${SOURCES})

target_sources(inventory-manager
PUBLIC 
    "src/main.cpp"
)

target_include_directories(inventory-manager
PUBLIC 
    "include"
)

install(TARGETS inventory-manager RUNTIME DESTINATION bin)
