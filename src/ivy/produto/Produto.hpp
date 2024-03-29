#pragma once
#include "log/IvyLog.hpp"
#include <fstream>

namespace ivy
{
/**
 * @brief Classe Produto, define um produto para o sistema de estoque Ivy
 * 
 */
class Produto
{
private:
    /**
     * @brief Nome do Produto
     * 
     */
    std::string m_nome;

    /**
     * @brief Marca do Produto
     * 
     */
    std::string m_marca;

    /**
     * @brief Valor do Produto
     * 
     */
    float m_valor;

    /**
     * @brief Numero de dentificacao do Produto
     * 
     */
    int m_id;

    /**
     * @brief Quantidade do Produto
     * 
     */
    int m_quantidade;

    /**
     * @brief Garantia do Produto
     * 
     */
    bool m_garantia;

public:
    /**
     * @brief Constroi um novo objeto de Produto
     * 
     * @param nId id do produto
     * @param nNome nome do produto
     * @param nMarca marca do produto
     * @param nValor valor do produto
     * @param nQtd quantiade do produto
     * @param nGarantia possui garantia
     */
    Produto(int nId, std::string nNome, std::string nMarca, float nValor, int nQtd, bool nGarantia);

    /**
     * @brief Construtor
     * 
     */
    Produto();

    /**
     * @brief Destrutor
     * 
     */
    ~Produto();

    /**
     * @brief Retorna o ID do produto
     * 
     * @return int& id do produto
     */
    const int &get_id() const;

    /**
     * @brief Define o ID do produto
     * 
     * @param nId id do produto
     */
    void set_id(int nId);

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
     * @brief Retorna a marca do produto
     * 
     * @return std::string& marca do produto
     */
    const std::string &get_marca() const;

    /**
     * @brief Define a marca do produto
     * 
     * @param nMarca marca do produto
     */
    void set_marca(std::string nMarca);

    /**
     * @brief Retorna a quantidade do produto
     * 
     * @return int& quantidade do produto
     */
    const int &get_quantidade() const;

    /**
     * @brief Define a quantidade do produto
     * 
     * @param qtd quantidade do porduto
     */
    void set_quantidade(int qtd);

    /**
     * @brief Retorna a garantia do porduto
     * 
     * @return true tem garantia
     * @return false nao tem garantia
     */
    const bool &get_garantia() const;

    /**
     * @brief Define a garantia do produto
     * 
     * @param nGarantia garantia do produto
     */
    void set_garantia(bool nGarantia);

    /**
     * @brief Retorna o valor do objeto
     * 
     * @return const float& valor do objeto
     */
    const float &get_valor() const;

    /**
     * @brief Defino o valor do objeto
     * 
     * @param nValor valor do objeto
    */
    void set_valor(float nValor);

    /**
     * @brief Retorna uma string com as informacoes do produto
     * 
     * @return std::string informacoes do produto
     */
    std::string to_string();

    /**
     * @brief Operador de comparacao
     * 
     * @param obj objeto a ser comparado
     * @return true se o objeto comparado for igual
     * @return false se o objeto comparado nao for igual
     */
    bool operator==(const Produto &obj);

    /**
     * @brief Operador de saida de arquivos
     * 
     * @param out stream de saida
     * @param obj objeto enviado para a saida
     * @return std::ostream& stream de saida
     */
    friend std::ostream &operator<<(std::ostream &out, const Produto &obj);

    /**
     * @brief Operador de entrada de arquivos
     * 
     * @param in stream de entradad
     * @param obj objeto construido com a entrada
     * @return std::istream& stream de entrada
     */
    friend std::istream &operator>>(std::istream &in, Produto &obj);
};
} // namespace ivy
