#include "IvyManager.hpp"

#include <iostream>
#include <cstdlib>

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
        IVY_INFO("{} : Editado", index);
    }
    else
        IVY_INFO("EDITAR::PRODUTO_NAO_ENCONTRADO");
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
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
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
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

int IvyManager::buscar_marca(std::string nMarca)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_marca() == nMarca)
            index = i;

    if (index != -1)
        return index;
    else
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
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
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
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
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

void IvyManager::vender(int nId, int nQuantidade)
{
    int index = this->buscar_id(nId);

    if (index != -1)
    {
        int tmp_qtd = this->m_estoque.get(index).get_quantidade();
        this->m_estoque.get(index).set_quantidade(tmp_qtd - nQuantidade);
        IVY_INFO("{} : Vendido", index);
    }
    else
        IVY_INFO("VENDA::PRODUTO_NAO_ENCONTRADO");
}

void IvyManager::comprar(int nId, int nQuantidade)
{
    int index = this->buscar_id(nId);

    if (index != -1)
    {
        int tmp_qtd = this->m_estoque.get(index).get_quantidade();
        this->m_estoque.get(index).set_quantidade(tmp_qtd + nQuantidade);
        IVY_INFO("{} : Comprado", index);
    }
    else
        IVY_INFO("COMPRA::PRODUTO_NAO_ENCONTRADO");
}

void IvyManager::salvar_estoque()
{
    std::ofstream m_outArquivo("estoque.txt");

    if (!m_outArquivo)
    {
        IVY_CRITICAL("Arquivo nao encontrado");
        std::cerr << "Arquivo nao pode ser aberto para gravacao\n";
    }
    else
    {
        m_outArquivo << m_estoque.get_tamanho() << std::endl;

        for (int i = 0; i < m_estoque.get_tamanho(); i++)
        {
            m_outArquivo << m_estoque.get(i);
        }

        m_outArquivo.close();
        IVY_INFO("IO::ARQUIVO_GERADO (estoque.txt)");
    }
}

void IvyManager::carregar_estoque()
{
    std::ifstream m_inArquivo("estoque.txt");

    if (!m_inArquivo)
    {
        IVY_CRITICAL("Arquivo nao encontrado");
        std::cerr << "Arquivo nao pode ser aberto para leitura\n";
    }
    else
    {
        int tam;

        if (!m_inArquivo.eof())
        {
            m_inArquivo >> tam;
            for (int i = 0; !m_inArquivo.eof() && i < tam; i++)
            {
                Produto p;
                m_inArquivo >> p;
                m_estoque.adicionar(p);
            }
        }
        m_inArquivo.close();
        IVY_INFO("IO::ARQUIVO_CARREGADO (estoque.txt)");
    }
}

} // namespace ivy
