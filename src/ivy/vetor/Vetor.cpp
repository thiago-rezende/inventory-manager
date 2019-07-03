#include "Vetor.hpp"

namespace ivy
{
template <typename _Tipo>
Vetor<_Tipo>::Vetor()
{
    this->m_capacidade = 5;
    this->m_tamanho = 0;
    this->m_dados = new _Tipo *[this->m_capacidade];
}

template <typename _Tipo>
Vetor<_Tipo>::~Vetor()
{
    for (int i = 0; i < m_tamanho; i++)
        delete this->m_dados[i];

    delete[] this->m_dados;
}

template <typename _Tipo>
void Vetor<_Tipo>::expandir()
{
    this->m_capacidade += 5;
    _Tipo **tmp_dados = new _Tipo *[m_capacidade];

    for (int i = 0; i < this->m_tamanho; i++)
        tmp_dados[i] = new _Tipo(*this->m_dados[i]);

    for (int i = 0; i < this->m_tamanho; i++)
        delete this->m_dados[i];

    delete[] this->m_dados;

    this->m_dados = tmp_dados;

    for (int i = 0; i < this->m_tamanho; i++)
        delete tmp_dados[i];

    delete[] tmp_dados;

    IVY_INFO("Vetor Expandido : capacidade -> {}", this->m_capacidade);
}

template <typename _Tipo>
void Vetor<_Tipo>::adicionar(_Tipo nElemento)
{
    if (this->m_tamanho >= this->m_capacidade)
        this->expandir();

    this->m_dados[this->m_tamanho++] = new _Tipo(nElemento);
    IVY_INFO("{} : Adicionado", this->m_tamanho - 1);
}

template <typename _Tipo>
void Vetor<_Tipo>::remover(int indice)
{
    if (indice >= this->m_tamanho || indice < 0)
        throw "Out of Bounds!";

    _Tipo **rmv_dados = new _Tipo *[this->m_capacidade];

    for (int i = 0; i < this->m_tamanho - 1; i++)
    {
        if (i < indice)
            rmv_dados[i] = new _Tipo(*this->m_dados[i]);
        else
            rmv_dados[i] = new _Tipo(*this->m_dados[i + 1]);
    }

    for (int i = 0; i < this->m_tamanho; i++)
        delete this->m_dados[i];

    delete[] this->m_dados;

    this->m_tamanho--;

    this->m_dados = rmv_dados;

    for (int i = 0; i < this->m_tamanho + 1; i++)
        delete rmv_dados[i];

    delete[] rmv_dados;

    IVY_INFO("{} : Removido", indice);
}

template <typename _Tipo>
_Tipo &Vetor<_Tipo>::get(int indice) const
{
    if (indice >= this->m_tamanho || indice < 0)
        throw "Out of Bounds!";

    return *this->m_dados[indice];
}

template <typename _Tipo>
const int &Vetor<_Tipo>::get_tamanho() const
{
    return this->m_tamanho;
}

template <typename _Tipo>
Vetor<_Tipo> &Vetor<_Tipo>::operator=(const Vetor<_Tipo> &other)
{
    if (this != &other)
    {
        _Tipo **nDados = new _Tipo *[other.m_capacidade];
        std::copy(other.m_dados, other.m_dados + other.m_tamanho, nDados);

        for (int i = 0; i < this->m_tamanho; i++)
            delete this->m_dados[i];

        delete[] this->m_dados;

        this->m_dados = nDados;
        this->m_tamanho = other.m_tamanho;
    }

    return *this;
}

template class Vetor<int>;
template class Vetor<float>;
template class Vetor<double>;
template class Vetor<char>;
template class Vetor<bool>;
template class Vetor<std::string>;
template class Vetor<Produto>;
template class Vetor<locadora::Jogo>;

} // namespace ivy
