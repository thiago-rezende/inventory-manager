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

    std::cout << "Vetor Expandido : capacidade -> " << this->m_capacidade << std::endl;
}

template <typename _Tipo>
void Vetor<_Tipo>::adicionar(_Tipo nElemento)
{
    if (this->m_tamanho >= this->m_capacidade)
        this->expandir();

    std::cout << this->m_tamanho << " : Adicionado" << std::endl;
    this->m_dados[this->m_tamanho++] = new _Tipo(nElemento);
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

    std::cout << indice << " : Removido" << std::endl;
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

template class Vetor<int>;
template class Vetor<float>;
template class Vetor<double>;
template class Vetor<char>;
template class Vetor<bool>;
template class Vetor<std::string>;
template class Vetor<Produto>;

} // namespace ivy
