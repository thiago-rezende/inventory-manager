#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "ivy_manager/IvyManager.hpp"
#include "log/IvyLog.hpp"
#include "locadora/LocadoraCLI.hpp"

namespace ivy
{
/**
 * @brief Classe InterfaceCLI
 * Realiza a interacao com o usuario
 */
class InterfaceCLI
{
private:
    /**
     * @brief Referencia para o objeto de IvyManager
     * 
     */
    IvyManager ivy_manager;

    /**
     * @brief Referencia para o objeto LocadoraCLI
     * 
     */
    std::unique_ptr<locadora::LocadoraCLI> m_locadoraCLI;

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
     * @brief Constroi um objeto de InterfaceCLI
     * 
     * @param nIvy_manager 
     */
    InterfaceCLI(IvyManager &nIvy_manager, locadora::Locadora nLocadora);

    /**
     * @brief Destroi o objeto de InterfaceCLI
     * 
     */
    ~InterfaceCLI();

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
     * @brief Abre a locadora
     * 
     */
    void locadora();

    /**
     * @brief Vende o produto
     * 
     */
    void vender();

    /**
     * @brief Compra um produto
     * 
     */
    void comprar();

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
} // namespace ivy
