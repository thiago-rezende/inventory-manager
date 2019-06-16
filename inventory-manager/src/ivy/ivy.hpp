#pragma once
#include <iostream>
#include "produto/Produto.hpp"
#include "vetor/Vetor.hpp"

namespace ivy
{
class IvyManager
{
private:
    Vetor<Produto> m_estoque;

public:
    IvyManager();
    ~IvyManager();

    void cadastrar(Produto nProduto);
    void editar(int nId, Produto nProduto);
    int buscar(std::string nNome);
    int buscar(float nValor);
    int buscar(int nQuantidade);
    void vender(int nId, int nQuantidade);
    void comprar(int nid, int nQuantidade);
};
} // namespace ivy
