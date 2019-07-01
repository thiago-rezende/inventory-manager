#pragma once
#include <string>
#include "log/IvyLog.hpp"

namespace ivy
{
namespace locadora
{
/**
 * @brief Classe Jogo, define um jogo para o sistema de estoque Ivy
 * 
 */
class Jogo
{
private:
    /**
     * @brief Numero de identificação do do Jogo
     * 
     */
    int jogoID;

    /**
     * @brief Nome do Jogo
     * 
     */
    std::string m_nome;

    /**
     * @brief Genero do Jogo
     * 
     */
    std::string m_genero;

    /**
     * @brief Preço da locação do Jogo
     * 
     */
    float m_valor;

    /**
     * @brief Disponibilidade do Jogo para aluguel
     * 
     */
    bool m_disponivel;

    /**
     * @brief Faixa etária do Jogo
     * 
     */
    int m_faixaEtaria;

public:
    /**
     * @brief Constroi um novo objeto de Jogo
     * 
     * @param nNome nome do produto
     * @param nGenero genero do produto
     * @param nFaixaEtaria faixa etária do jogo
     * @param nValor valor do produto
     * @param nDisponivel disponibilidade do produto
     */
    Jogo(std::string nNome, std::string nGenero, int nFaixaEtaria, float nValor, bool nDisponivel);

    /**
     * @brief Construtor
     * 
     */
    Jogo();

    /**
     * @brief Destrutor
     * 
     */
    ~Jogo();

    /**
     * @brief Retorna o ID do jogo
     * 
     * @return int& id do jogo
     */
    const int &get_jogoID() const;

    /**
     * @brief Define o ID do produto
     * 
     * @param nJogoID do produto
     */
    void set_jogoID(int nJogoID);

    /**
     * @brief Retorna o nome do produto
     * 
     * @return std::string& nome do produto
     */
    const std::string &get_nome() const;

    /**
     * @brief Define o nome do produto
     * 
     * @param nNome nome do produto
     */
    void set_nome(std::string nNome);

    /**
     * @brief Retorna o nome do produto
     * 
     * @return std::string& genero do produto
     */
    const std::string &get_genero() const;

    /**
     * @brief Define o genero do produto
     * 
     * @param nGenero genero do produto
     */
    void set_genero(std::string nGenero);

    /**
     * @brief Retorna a faixa etária do produto
     * 
     * @return int& faixa etária do produto
     */
    const int &get_faixaEtaria() const;

    /**
     * @brief Define a faixa etária do produto
     * 
     * @param nFaixaEtaria faixa etária do produto
     */
    void set_faixaEtaria(int nFaixaEtaria);

    /**
     * @brief Retorna o valor do produto
     * 
     * @return float& valor do produto
     */
    const float &get_valor() const;

    /**
     * @brief Define o valor do produto
     * 
     * @param nValor valor do produto
     */
    void set_valor(float nValor);

    /**
     * @brief Retorna a disponibilidade do produto
     * 
     * @return bool& disponibilidade do produto
     */
    const bool &get_disponivel() const;

    /**
     * @brief Define a disponibilidade do produto para locação
     * 
     * @param nDisponivel disponibilidade do produto
     */
    void set_disponivel(bool nDisponivel);

    /**
     * @brief Retorna uma string com as informacoes do jogo
     * 
     * @return std::string informacoes do jogo
     */
    std::string to_string();
};
} // namespace locadora
} // namespace ivy
