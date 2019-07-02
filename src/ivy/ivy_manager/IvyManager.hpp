#pragma once
#include "produto/Produto.hpp"
#include "vetor/Vetor.hpp"
#include "log/IvyLog.hpp"

namespace ivy
{
/**
 * @brief Classe IvyManager
 * 
 */
class IvyManager
{
private:
    /**
     * @brief Estoque de vetor dos produtos 
     * 
     */
    Vetor<Produto> m_estoque;

public:
    /**
     * @brief Constroi um novo objeto de IvyManager
     * 
     */
    IvyManager();

    /**
     * @brief Destroi o objeto de IvyManager
     * 
     */
    ~IvyManager();

    /**
     * @brief Retorna o Vetor do estoque
     * 
     * @return const Vetor<Produto>& vetor do estoque
     */
    const Vetor<Produto> &get_estoque() const;

    /**
     * @brief Cadastra um novo Produto no estoque
     * 
     * @param nProduto produto a ser cadastrado
     */
    void cadastrar(Produto nProduto);

    /**
     * @brief Edita um produto no estoque
     * 
     * @param nId numero de identificacao do produto
     * @param nProduto produto editado
     */
    void editar(int nId, Produto nProduto);

    /**
     * @brief Busca um produto pelo nome
     * 
     * @param nNome nome do produto
     * @return int indice do produto no estoque
     */
    int buscar_nome(std::string nNome);

    /**
     * @brief Busca um produto pela marca
     * 
     * @param nMarca marca do produto
     * @return int indice do produto no estoque
     */
    int buscar_marca(std::string nMarca);

    /**
     * @brief Busca um produto pelo valor
     * 
     * @param nValor valor do produto
     * @return int indice do produto no estoque
     */
    int buscar_valor(float nValor);

    /**
     * @brief Busca um produto pela quantidade
     * 
     * @param nQuantidade quantidade do produto
     * @return int indice do produto no estoque
     */
    int buscar_quantidade(int nQuantidade);

    /**
     * @brief Busca um produto pelo numero de identificacao
     * 
     * @param nId numero de identificacao do produto
     * @return int indice do produto no estoque
     */
    int buscar_id(int nId);

    /**
     * @brief Vende um produto
     * 
     * @param nId numero de identificacao do produto
     * @param nQuantidade quantidade a ser vendida
     */
    void vender(int nId, int nQuantidade);

    /**
     * @brief Adiciona quantidade ao estoque
     * 
     * @param nId numero de identificacao do produto
     * @param nQuantidade quantidade do produto no estoque
     */
    void comprar(int nId, int nQuantidade);

    /**
     * @brief Busca varios produtos de uma marca
     * 
     * @param nMarca marca a ser buscada
     * @return Vetor<Produto> vetor de produtos encontrados
     */
    Vetor<Produto> buscar_variosMarca(std::string nMarca);

    /**
     * @brief Busca varios produtos de um valor
     * 
     * @param nValor valor a ser buscado
     * @return Vetor<Produto> vetor de produtos encontrados
     */
    Vetor<Produto> buscar_variosValor(float nValor);

    /**
     * @brief Busca varios produtos de uma quantidade
     * 
     * @param nQuantidade quantidade a ser buscada
     * @return Vetor<Produto> vetor de produtos encontrados
     */
    Vetor<Produto> buscar_variosQuantidade(int nQuantidade);

    /**
     * @brief Salva o estoque em um arquivo
     * 
     */
    void salvar_estoque();

    /**
     * @brief Carrega o estoque de um arquivo
     * 
     */
    void carregar_estoque();
};
} // namespace ivy
