#pragma once
#include <iostream>
#include "../produto/Produto.hpp"

namespace ivy
{
class Vetor
{
private:
    int m_capacidade, m_tamanho;
    Produto **m_dados;

    void expandir();

public:
    Vetor();
    ~Vetor();

    void adicionar(Produto nProduto);
    void remover(int indice);
    Produto &get(int indice) const;
    const int &get_tamanho() const;
};
} // namespace ivy
