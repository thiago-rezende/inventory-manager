#pragma once

#include "ivy_manager/IvyManager.hpp"
#include "forms/include_nana.hpp"
#include "log/IvyLog.hpp"

namespace ivy
{
/**
 * @brief Classe InterfaceGUI
 * Gerencia a interface grafica
 */
class InterfaceGUI
{
private:
    /**
     * @brief Largura da janela
     * 
     */
    unsigned int m_screenWidth;

    /**
     * @brief Altura da janela
     * 
     */
    unsigned int m_screenHeight;

    /**
     * @brief Titulo da janela
     * 
     */
    std::string m_title;

public:
    /**
     * @brief Objeto de IvyManager
     * 
     */
    IvyManager m_ivyManager;

    /**
     * @brief Constroi um novo objeto de InterfaceGUI
     * 
     * @param nScreenWidth largura da janela
     * @param nScreenHeight altura da janela
     * @param nTitel titulo da janela
     */
    InterfaceGUI(unsigned int nScreenWidth, unsigned int nScreenHeight, std::string nTitel);

    /**
     * @brief Destroi o objeto de InterfaceGUI
     * 
     */
    ~InterfaceGUI();

    /**
     * @brief Inicia o looping principal da InterfaceGUI
     * 
     */
    void run();
};
} // namespace ivy
