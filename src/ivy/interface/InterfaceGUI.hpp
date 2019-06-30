#pragma once

#include "ivy_manager/IvyManager.hpp"
#include "forms/include_nana.hpp"
#include "log/IvyLog.hpp"

namespace ivy
{
class InterfaceGUI
{
private:
    unsigned int m_screenWidth;
    unsigned int m_screenHeight;
    std::string m_title;

public:
    IvyManager m_ivyManager;
    InterfaceGUI(unsigned int nScreenWidth, unsigned int nScreenHeight, std::string nTitel);
    ~InterfaceGUI();

    void run();
};
} // namespace ivy
