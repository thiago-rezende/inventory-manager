#include "Produto.hpp"

namespace ivy
{
Produto::Produto(std::string nNome, std::string nMarca, float nValor, int nQtd, bool nGarantia)
{
    this->m_nome = nNome;
    this->m_marca = nMarca;
    this->m_valor = nValor;
    this->m_quantidade = nQtd;
    this->m_garantia = nGarantia;
}

Produto::~Produto() {}

int Produto::get_id() const
{
    return this->m_id;
}

void Produto::set_id(int nId)
{
    this->m_id = nId;
}

std::string Produto::get_nome() const
{
    return this->m_nome;
}

void Produto::set_nome(std::string nNome)
{
    this->m_nome = nNome;
}

std::string Produto::get_marca() const
{
    return this->m_marca;
}

void Produto::set_marca(std::string nMarca)
{
    this->m_marca = nMarca;
}

int Produto::get_quantidade() const
{
    return this->m_quantidade;
}

void Produto::set_quantidade(int nQuantidade)
{
    this->m_quantidade = nQuantidade;
}

bool Produto::get_garantia() const
{
    return this->m_garantia;
}

void Produto::set_garantia(bool nGarantia)
{
    this->m_garantia = nGarantia;
}

} // namespace ivy
