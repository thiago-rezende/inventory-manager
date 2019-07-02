#include "Locadora.hpp"

namespace ivy
{
namespace locadora
{

Locadora::Locadora()
{
}

Locadora::~Locadora()
{
}

const Vetor<Jogo> &Locadora::get_estoque() const
{
    return this->m_estoque;
}

void Locadora::cadastrar(Jogo nJogo)
{
    this->m_estoque.adicionar(nJogo);
}

int Locadora::buscar_faixaEtaria(int nFaixaEtaria)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_faixaEtaria() == nFaixaEtaria)
            index = i;

    if (index != -1)
        return index;
    else
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

int Locadora::buscar_alugado(bool nDisponivel)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_disponivel() == nDisponivel)
            index = i;

    if (index != -1)
        return index;
    else
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

int Locadora::buscar_genero(std::string nGenero)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_genero() == nGenero)
            index = i;

    if (index != -1)
        return index;
    else
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

int Locadora::buscar_id(int nJogoID)
{
    int index = -1;

    for (int i = 0; i < this->m_estoque.get_tamanho(); i++)
        if (this->m_estoque.get(i).get_jogoID() == nJogoID)
            index = i;

    if (index != -1)
        return index;
    else
    {
        IVY_INFO("BUSCA::PRODUTO_NAO_ENCONTRADO");
        return index;
    }
}

int Locadora::buscar_nome(std::string nNome)
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

void Locadora::editar(int nJogoID, Jogo nJogo)
{
    int index = this->buscar_id(nJogoID);

    if (index != -1)
    {
        this->m_estoque.get(index).set_jogoID(nJogo.get_jogoID());
        this->m_estoque.get(index).set_nome(nJogo.get_nome());
        this->m_estoque.get(index).set_genero(nJogo.get_genero());
        this->m_estoque.get(index).set_valor(nJogo.get_valor());
        this->m_estoque.get(index).set_faixaEtaria(nJogo.get_faixaEtaria());
    }
    else
        IVY_INFO("EDITAR::PRODUTO_NAO_ENCONTRADO");
}

void Locadora::alugar(int nJogoID)
{
    int index = this->buscar_id(nJogoID);

    if (index != -1)
        this->m_estoque.get(index).set_disponivel(false);

    else
        IVY_INFO("COMPRA::PRODUTO_NAO_ENCONTRADO");
}

void Locadora::devolver(int nJogoID)
{
    int index = this->buscar_id(nJogoID);

    if (index != -1)
        this->m_estoque.get(index).set_disponivel(true);

    else
        IVY_INFO("COMPRA::PRODUTO_NAO_ENCONTRADO");
}

void Locadora::salvar_estoque()
{
    std::ofstream m_outArquivo("locadora.txt");

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
        IVY_INFO("IO::ARQUIVO_GERADO (locadora.txt)");
    }
}

void Locadora::carregar_estoque()
{
    std::ifstream m_inArquivo("locadora.txt");

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
                Jogo j;
                m_inArquivo >> j;
                m_estoque.adicionar(j);
            }
        }
        m_inArquivo.close();
        IVY_INFO("IO::ARQUIVO_CARREGADO (locadora.txt)");
    }
}

} // namespace locadora
} // namespace ivy