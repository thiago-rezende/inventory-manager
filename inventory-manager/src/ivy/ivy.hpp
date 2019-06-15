#pragma once
#include <iostream>

namespace ivy
{
class IvyManager
{
private:
    ivy::Vetor m_estoque;

public:
    IvyManager();
    ~IvyManager();

    void cadastrar();
    void editar(std::string nNome);
    int buscar(std::string nNome);
    int buscar(float nPreco);
    int buscar(int nQuantidade);
    void vender(int nId, int nQuantidade);
    void comprar(int nid, int nQuantidade);
};
} // namespace ivy
