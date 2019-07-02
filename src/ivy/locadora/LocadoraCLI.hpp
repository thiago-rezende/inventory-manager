#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "Locadora.hpp"
#include "log/IvyLog.hpp"

namespace ivy
{
namespace locadora
{
/**
 * @brief Classe LocadoraCLI
 * Realiza a interacao com o usuario
 */
class LocadoraCLI
{
private:
    /**
     * @brief Referencia para o objeto de Locadora
     * 
     */
    Locadora m_locadora;

    /**
     * @brief Determina quando o programa deve sair
     * 
     */
    bool sair;

    /**
     * @brief Opcoes digitadas pelo usuario
     * 
     */
    std::string opt;

public:
    /**
     * @brief Constroi um objeto de LocadoraCLI
     * 
     * @param nLocadora 
     */
    LocadoraCLI(Locadora &nLocadora);

    /**
     * @brief Destroi o objeto de LocadoraCLI
     * 
     */
    ~LocadoraCLI();

    /**
     * @brief Inicia o programa
     * 
     */
    void run();

    /**
     * @brief Logo do programa
     * 
     */
    void logo();

    /**
     * @brief Menu do programa para escolher opcoes
     * 
     */
    void menu();

    /**
     * @brief Controle das opcoes
     * 
     */
    void option_handler();

    /**
     * @brief Mostra as opcoes
     * 
     */
    void ajuda();

    /**
     * @brief Entrada dos dados do produto
     * 
     */
    void cadastrar();

    /**
     * @brief Edita um produto
     * 
     */
    void editar();

    /**
     * @brief Busca um produto no estoque
     * 
     */
    void buscar();

    /**
     * @brief Alterar o status do jogo para alugado
     * 
     */
    void alugar();

    /**
     * @brief Alterar o status do jogo de alugado para disponível
     * 
     */
    void devolver();

    /**
     * @brief Busca varios jogos de um genero
     * 
     * @param nGenero genero a ser buscado
     */
    void buscar_generoCLI(std::string nGenero);

    /**
     * @brief busca varios jogos alugados ou nao
     * 
     * @param nAlugado estado do jogo, alugado ou nao
     */
    void buscar_alugadoCLI(bool nAlugado);

    /**
     * @brief Busca varios jogos de uma classificacao
     * 
     * @param nClassificacao classificacao a ser buscada
     */
    void buscar_classificacaoCLI(int nClassificacao);

    /**
     * @brief Lista todos os jogos do estoque
     * 
     */
    void listar_jogos();

    /**
     * @brief Salva os dados do estoque em um arquivo
     * 
     */
    void salvar();

    /**
     * @brief Carrega os dados do estoque de um arquivo
     * 
     */
    void carregar();
};
} // namespace locadora
} // namespace ivy
