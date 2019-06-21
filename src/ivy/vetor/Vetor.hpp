#pragma once
#include <iostream>
#include "produto/Produto.hpp"

namespace ivy
{
/**
 * @brief Classe Vetor para manipulacao de vetores
 * 
 */
template <typename _Tipo>
class Vetor
{
private:
    /**
     * @brief Capacidade do Vetor
     * 
     */
    int m_capacidade;

    /**
     * @brief Tamanho do Vetor
     * 
     */
    int m_tamanho;

    /**
     * @brief Dados do Vetor
     * 
     */
    _Tipo **m_dados;

    /**
     * @brief Aumenta a capacidade do Vetor em 5
     * 
     */
    void expandir();

public:
    /**
     * @brief Construct a new Vetor object
     * 
     */
    Vetor();

    /**
     * @brief Destroy the Vetor object
     * 
     */
    ~Vetor();

    /**
     * @brief Adiciona um novo elemento no Vetor
     * 
     * @param nElemento elemento a ser adicionado
     */
    void adicionar(_Tipo nElemento);

    /**
     * @brief Remove um elemento do Vetor
     * 
     * @param indice posicao do elemento a ser removido
     */
    void remover(int indice);

    /**
     * @brief Retorna um elemento do Vetor
     * 
     * @param indice posicao do elemento a ser removido
     * @return Produto& elemento do vetor
     */
    _Tipo &get(int indice) const;

    /**
     * @brief Pega o tamanho do vetor
     * 
     * @return const int& tamanho do vetor
     */
    const int &get_tamanho() const;

    /**
     * @brief Operador de atribuicao
     * 
     * @param other Vetor a ser atribuido
     * @return Vetor<_Tipo>& Vetor a receber a atribuicao
     */
    Vetor<_Tipo> &operator=(const Vetor<_Tipo> &other);
};
} // namespace ivy
