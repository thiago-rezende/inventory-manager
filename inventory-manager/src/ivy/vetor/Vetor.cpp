#include "Vetor.hpp"

namespace ivy
{
Vetor::Vetor()
{
    this->m_capacidade = 5;
    this->m_tamanho = 0;
    this->m_dados = new Produto *[this->m_capacidade];
}

Vetor::~Vetor()
{
    for (int i = 0; i < m_tamanho; i++)
        delete this->m_dados[i];

    delete[] this->m_dados;
}

void Vetor::expandir()
{
    this->m_capacidade += 5;
    Produto **tmp_dados = new Produto *[m_capacidade];

    for (int i = 0; i < this->m_tamanho; i++)
        tmp_dados[i] = new Produto(*this->m_dados[i]);

    for (int i = 0; i < this->m_tamanho; i++)
        delete this->m_dados[i];

    delete this->m_dados;

    this->m_dados = tmp_dados;

    std::cout << "Vetor Expandido : capacidade -> " << this->m_capacidade << std::endl;
}

void Vetor::adicionar(Produto nProduto)
{
    if (this->m_tamanho >= this->m_capacidade)
        this->expandir();

    std::cout << this->m_tamanho << " : Adicionado" << std::endl;
    this->m_dados[this->m_tamanho++] = new Produto(nProduto);
}

Produto &Vetor::get(int indice) const
{
    if (indice >= this->m_tamanho)
        throw "Out of Bounds!";

    return *this->m_dados[indice];
}
} // namespace ivy
