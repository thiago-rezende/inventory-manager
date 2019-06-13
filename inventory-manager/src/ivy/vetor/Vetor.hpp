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
    Produto &get(int id) const;
};
} // namespace ivy
