#include "ivy.hpp"

namespace ivy
{
IvyManager::IvyManager()
{
}

IvyManager::~IvyManager()
{
}

void IvyManager::cadastrar(Produto nProduto)
{
    this->m_estoque.adicionar(nProduto);
}

void IvyManager::editar(int nId, Produto nProduto)
{
}

int IvyManager::buscar(std::string nNome)
{
    int nId = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_nome() == nNome)
            nId = i;

    if (nId != -1)
        return nId;
    else
    {
        std::cout << "Nao encontrado!" << std::endl;
        return nId;
    }
}

int IvyManager::buscar(float nValor)
{
    int nId = -1;

    for (int i = 0; i < this->m_estoque.get_valor(); i++)
        if (this->m_estoque.get(i).get_valor() == nValor)
            nId = i;

    if (nId != -1)
        return nId;
    else
    {
        std::cout << "Nao encontrado!" << std::endl;
        return nId;
    }
}

int IvyManager::buscar(int nQuantidade)
{
    int nId = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_quantidade() == nQuantidade)
            nId = i;

    if (nId != -1)
        return nId;
    else
    {
        std::cout << "Nao encontrado!" << std::endl;
        return nId;
    }
}

void IvyManager::vender(int nId, int nQuantidade)
{
}

void IvyManager::comprar(int nid, int nQuantidade)
{
}
} // namespace ivy
