#include "Produto.hpp"

namespace ivy
{
Produto::Produto(int nId, std::string nNome, std::string nMarca, float nValor, int nQtd, bool nGarantia)
{
    this->m_id = nId;
    this->m_nome = nNome;
    this->m_marca = nMarca;
    this->m_valor = nValor;
    this->m_quantidade = nQtd;
    this->m_garantia = nGarantia;
}

Produto::Produto()
{
    this->m_nome = "UNKNOWN";
    this->m_marca = "UNKNOWN";
    this->m_valor = 0.0f;
    this->m_quantidade = 0;
    this->m_garantia = false;
}

Produto::~Produto() {}

const int &Produto::get_id() const
{
    return this->m_id;
}

void Produto::set_id(int nId)
{
    this->m_id = nId;
}

const std::string &Produto::get_nome() const
{
    return this->m_nome;
}

void Produto::set_nome(std::string nNome)
{
    this->m_nome = nNome;
}

const std::string &Produto::get_marca() const
{
    return this->m_marca;
}

void Produto::set_marca(std::string nMarca)
{
    this->m_marca = nMarca;
}

const int &Produto::get_quantidade() const
{
    return this->m_quantidade;
}

void Produto::set_quantidade(int nQuantidade)
{
    this->m_quantidade = nQuantidade;
}

const bool &Produto::get_garantia() const
{
    return this->m_garantia;
}

void Produto::set_garantia(bool nGarantia)
{
    this->m_garantia = nGarantia;
}

const float &Produto::get_valor() const
{
    return this->m_valor;
}

void Produto::set_valor(float nValor)
{
    this->m_valor = nValor;
}

std::string Produto::to_string()
{
    std::string saida;

    saida += "|ID: " + std::to_string(m_id);
    saida += " | Nome: " + m_nome;
    saida += " | Marca: " + m_marca;
    saida += " | Valor: " + std::to_string(m_valor);
    saida += " | Quantidade: " + std::to_string(m_quantidade);
    std::string tmp_garantia = (m_garantia ? "Sim" : "Nao");
    saida += " | Garantia: " + tmp_garantia;
    saida += "|";

    return saida;
}

bool Produto::operator==(const Produto &obj)
{
    return (m_id == obj.get_id()) &&
           (m_nome == obj.get_nome()) &&
           (m_marca == obj.get_marca()) &&
           (m_valor == obj.get_valor()) &&
           (m_quantidade == obj.get_quantidade()) &&
           (m_garantia == obj.get_garantia());
}

std::ostream &operator<<(std::ostream &out, const Produto &obj)
{
    out << obj.m_id << "\n"
        << obj.m_nome << "\n"
        << obj.m_marca << "\n"
        << obj.m_valor << "\n"
        << obj.m_quantidade << "\n"
        << obj.m_garantia << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Produto &obj)
{
    in >> obj.m_id;
    in >> obj.m_nome;
    in >> obj.m_marca;
    in >> obj.m_valor;
    in >> obj.m_quantidade;
    in >> obj.m_garantia;
    return in;
}

} // namespace ivy
