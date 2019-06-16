#include "IvyManager.hpp"

namespace ivy
{
IvyManager::IvyManager()
{
}

IvyManager::~IvyManager()
{
}

const Vetor<Produto> &IvyManager::get_estoque() const
{
    return this->m_estoque;
}

void IvyManager::cadastrar(Produto nProduto)
{
    this->m_estoque.adicionar(nProduto);
}

void IvyManager::editar(int nId, Produto nProduto)
{
    int index = this->buscar_id(nId);

    if (index != -1)
    {
        this->m_estoque.get(index).set_id(nProduto.get_id());
        this->m_estoque.get(index).set_nome(nProduto.get_nome());
        this->m_estoque.get(index).set_marca(nProduto.get_marca());
        this->m_estoque.get(index).set_valor(nProduto.get_valor());
        this->m_estoque.get(index).set_quantidade(nProduto.get_quantidade());
        this->m_estoque.get(index).set_garantia(nProduto.get_garantia());
    }
    else
        std::cout << "EDITAR::PRODUTO_NAO_ENCONTRADO" << std::endl;
}

int IvyManager::buscar_id(int nId)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_id() == nId)
            index = i;

    if (index != -1)
        return index;
    else
        std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
}

int IvyManager::buscar_nome(std::string nNome)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_nome() == nNome)
            index = i;

    if (index != -1)
        return index;
    else
    {
        std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
        return index;
    }
}

int IvyManager::buscar_valor(float nValor)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_valor() == nValor)
            index = i;

    if (index != -1)
        return index;
    else
    {
        std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
        return index;
    }
}

int IvyManager::buscar_quantidade(int nQuantidade)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_quantidade() == nQuantidade)
            index = i;

    if (index != -1)
        return index;
    else
    {
        std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
        return index;
    }
}

void IvyManager::vender(int nId, int nQuantidade)
{
    int index = this->buscar_id(nId);

    if (index != -1)
    {
        int tmp_qtd = this->m_estoque.get(index).get_quantidade();
        this->m_estoque.get(index).set_garantia(tmp_qtd - nQuantidade);
    }
    else
        std::cout << "VENDA::PRODUTO_NAO_ENCONTRADO" << std::endl;
}

void IvyManager::comprar(int nId, int nQuantidade)
{
    int index = this->buscar_id(nId);

    if (index != -1)
    {
        int tmp_qtd = this->m_estoque.get(index).get_quantidade();
        this->m_estoque.get(index).set_quantidade(tmp_qtd + nQuantidade);
    }
    else
        std::cout << "COMPRA::PRODUTO_NAO_ENCONTRADO" << std::endl;
}
} // namespace ivy
