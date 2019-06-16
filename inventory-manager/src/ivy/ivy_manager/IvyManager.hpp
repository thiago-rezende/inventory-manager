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

    const Vetor<Produto> &get_estoque() const;
    void cadastrar(Produto nProduto);
    void editar(int nId, Produto nProduto);
    int buscar_nome(std::string nNome);
    int buscar_valor(float nValor);
    int buscar_quantidade(int nQuantidade);
    int buscar_id(int nId);
    void vender(int nId, int nQuantidade);
    void comprar(int nId, int nQuantidade);
};
} // namespace ivy
