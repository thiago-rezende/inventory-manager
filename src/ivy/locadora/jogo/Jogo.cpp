#include "Jogo.hpp"

namespace ivy
{
namespace locadora
{
Jogo::Jogo(std::string nNome, std::string nGenero, int nFaixaEtaria, float nValor, bool nDisponivel)
{
    this->m_nome = nNome;
    this->m_genero = nGenero;
    this->m_valor = nValor;
    this->m_disponivel = nDisponivel;
    this->m_faixaEtaria = nFaixaEtaria;
}

Jogo::Jogo()
{
    this->m_nome = "UNKNOWN";
    this->m_genero = "UNKNOWN";
    this->m_valor = 0.0f;
    this->m_disponivel = false;
    this->m_faixaEtaria = 18;
}

Jogo::~Jogo() {}

const std::string &Jogo::get_nome() const
{
    return this->m_nome;
}

const int &Jogo::get_jogoID() const
{
    return this->jogoID;
}

void Jogo::set_jogoID(int nJogoID)
{
    this->jogoID = nJogoID;
}

void Jogo::set_nome(std::string nNome)
{
    this->m_nome = nNome;
}

void Jogo::set_genero(std::string nGenero)
{
    this->m_genero = nGenero;
}

const std::string &Jogo::get_genero() const
{
    return this->m_genero;
}

const float &Jogo::get_valor() const
{
    return this->m_valor;
}

void Jogo::set_valor(float nValor)
{
    this->m_valor = nValor;
}

const int &Jogo::get_faixaEtaria() const
{
    return this->m_faixaEtaria;
}

void Jogo::set_faixaEtaria(int nFaixaEtaria)
{
    this->m_faixaEtaria = nFaixaEtaria;
}

const bool &Jogo::get_disponivel() const
{
    return this->m_disponivel;
}

void Jogo::set_disponivel(bool nDisponivel)
{
    this->m_disponivel = nDisponivel;
}

std::string Jogo::to_string()
{
    std::string saida;

    saida += "|ID: " + std::to_string(this->jogoID);
    saida += " | Nome: " + this->m_nome;
    saida += " | Genero: " + this->m_genero;
    saida += " | Valor: " + std::to_string(this->m_valor);
    saida += " | Faixa etaria: " + std::to_string(this->m_faixaEtaria);
    std::string tmp_disponivel = (this->m_disponivel ? "Sim" : "Nao");
    saida += " | Disponivel: " + tmp_disponivel;
    saida += "|";

    return saida;
}

} // namespace locadora
} // namespace ivy
