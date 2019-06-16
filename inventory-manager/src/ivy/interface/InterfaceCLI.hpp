#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "../ivy_manager/IvyManager.hpp"

namespace ivy
{
class InterfaceCLI
{
private:
    IvyManager ivy_manager;
    bool sair;
    std::string opt;

public:
    InterfaceCLI(IvyManager *nIvy_manager);
    ~InterfaceCLI();

    void run();
    void logo();
    void menu();
    void option_handler();
    void ajuda();
    void cadastrar();
    void editar();
    void buscar();
    void vender();
    void comprar();
};
} // namespace ivy
