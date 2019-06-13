#pragma once
#include <iostream>
#include "../produto/Produto.hpp"

namespace ivy
{
/**
 * @brief Classe Vetor para manipulacao de vetores
 * 
 */
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
    Produto **m_dados;

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
     * @param nProduto elemento a ser adicionado
     */
    void adicionar(Produto nProduto);

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
    Produto &get(int indice) const;

    /**
     * @brief Pega o tamanho do vetor
     * 
     * @return const int& tamanho do vetor
     */
    const int &get_tamanho() const;
};
} // namespace ivy
