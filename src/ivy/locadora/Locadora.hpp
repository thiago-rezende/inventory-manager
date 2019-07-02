#pragma once
#include "jogo/Jogo.hpp"
#include "vetor/Vetor.hpp"
#include "log/IvyLog.hpp"
#include <iostream>

namespace ivy
{
namespace locadora
{
class Locadora
{
private:
    Vetor<Jogo> m_estoque;

public:
    /**
     * @brief Constroi um objeto de Locadora
     * 
     */
    Locadora();

    /**
     * @brief Destroi o objeto de Locadora
     * 
     */
    ~Locadora();

    /**
     * @brief Retorna o estoque
     * 
     * @return const Vetor<Jogo>& estoque
     */
    const Vetor<Jogo> &get_estoque() const;

    /**
     * @brief Cadastra um novo jogo
     * 
     * @param nJogo Jogo a ser cadastrado
     */
    void cadastrar(Jogo nJogo);

    /**
     * @brief Busca um jogo por faixa etaria
     * TODO: retornar um vetor de jogos
     * @param nFaixaEtaria faixa etaria
     * @return int indice do jogo no estoque
     */
    int buscar_faixaEtaria(int nFaixaEtaria);

    /**
     * @brief Busca jogos por estado de locacao
     * TODO: retornar um vetor de jogos
     * @param nDisponivel alugados ou nao
     * @return int indices
     */
    int buscar_alugado(bool nDisponivel);

    /**
     * @brief Busca jogos por genero
     * 
     * @param nGenero genero
     * @return int indice
     */
    int buscar_genero(std::string nGenero);

    /**
     * @brief Busca um jogo por id
     * 
     * @param nJogoID id do jogo
     * @return int indice do jogo no vetor
     */
    int buscar_id(int nJogoID);

    /**
     * @brief Busca um jogo por nome
     * 
     * @param nNome nome do jogo
     * @return int indice do jogo no vetor
     */
    int buscar_nome(std::string nNome);

    /**
     * @brief Edita jogo
     * 
     * @param nJogoID id do jogo
     * @param nJogo objeto Jogo com os novos valores
     */
    void editar(int nJogoID, Jogo nJogo);

    /**
     * @brief Aluga um jogo
     * 
     * @param nJogoID id do jogo
     */
    void alugar(int nJogoID);

    /**
     * @brief Devolucao de produto
     * 
     * @param nJogoID alugados ou nao
     */
    void devolver(int nJogoID);

    /**
     * @brief Busca varios jogos de um genero
     * 
     * @param nGenero genero a ser buscado
     * @return Vetor<Jogo> vetor de jogos encontrados
     */
    Vetor<Jogo> buscar_variosGenero(std::string nGenero);

    /**
     * @brief Busca varios jogos alugados
     * 
     * @param nAlugado alugados ou nao
     * @return Vetor<Jogo> vetor de jogos encontrados
     */
    Vetor<Jogo> buscar_variosAlugado(bool nAlugado);

    /**
     * @brief Busca varios jogos de uma classificacao
     * 
     * @param nClassificacao classificacao a ser buscada
     * @return Vetor<Jogo> vetor de jogos encontrados
     */
    Vetor<Jogo> buscar_variosClassificacao(int nClassificacao);

    /**
     * @brief Busca varios jogos por um nome
     * 
     * @param nNome nome a ser buscado
     * @return Vetor<Jogo> vetor de jogos encontrados
     */
    Vetor<Jogo> buscar_variosNome(std::string nNome);

    /**
     * @brief Salva os dados do estoque em um arquivo
     * 
     */
    void salvar_estoque();

    /**
     * @brief Salva os dados do estoque disponiveis ou nao
     * 
     * @param nDisponivel disponibilidade do jogo
     */
    void salvar_estoqueDisponivel(bool nDisponivel);

    /**
     * @brief Carregar o estoque de um arquivo
     * 
     */
    void carregar_estoque();
};
} // namespace locadora
} // namespace ivy
