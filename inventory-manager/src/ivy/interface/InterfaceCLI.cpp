#include "InterfaceCLI.hpp"

namespace ivy
{
InterfaceCLI::InterfaceCLI(IvyManager *nIvy_manager)
{
    this->sair = false;
}

InterfaceCLI::~InterfaceCLI()
{
}

void InterfaceCLI::run()
{
    this->logo();

    while (!this->sair)
    {
        this->menu();
        this->option_handler();
    }
}

void InterfaceCLI::logo()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << R"( _____             __  __                                   )" << std::endl;
    std::cout << R"(|_   _|           |  \/  |                                  )" << std::endl;
    std::cout << R"(  | |_   ___   _  | \  / | __ _ _ __   __ _  __ _  ___ _ __ )" << std::endl;
    std::cout << R"(  | \ \ / / | | | | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__|)" << std::endl;
    std::cout << R"( _| |\ V /| |_| | | |  | | (_| | | | | (_| | (_| |  __/ |   )" << std::endl;
    std::cout << R"(|_____\_/  \__, | |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_|   )" << std::endl;
    std::cout << R"(            __/ |                            __/ |          )" << std::endl;
    std::cout << R"(           |___/                            |___/           )" << std::endl;
    std::cout << std::endl;

    std::cout << "Pressione enter para iniciar ..." << std::endl;
    std::cin.get();
}

void InterfaceCLI::menu()
{
    std::cout << "IvyManeger > ";

    std::getline(std::cin, this->opt);
    std::transform(this->opt.begin(), this->opt.end(), this->opt.begin(), ::tolower);
    std::cout << std::endl;
}

void InterfaceCLI::option_handler()
{
    if (this->opt == "ajuda")
        this->ajuda();
    else if (this->opt == "cadastrar")
        this->cadastrar();
    else if (this->opt == "editar")
        this->editar();
    else if (this->opt == "buscar")
        this->buscar();
    else if (this->opt == "vender")
        this->vender();
    else if (this->opt == "comprar")
        this->comprar();
    else if (this->opt == "sair")
        this->sair = true;
    else
    {
        std::cout << "Opcao invalida, digite ajuda para ver os comandos." << std::endl;
        std::cout << std::endl;
    }
}

void InterfaceCLI::ajuda()
{
    std::cout << std::endl;
    std::cout << "Comandos: " << std::endl;
    std::cout << "ajuda => Exibe os comandos disponiveis." << std::endl;
    std::cout << "cadastrar => Cadastrar um novo Produto." << std::endl;
    std::cout << "editar => Editar um Produto." << std::endl;
    std::cout << "buscar => Buscar um Produto." << std::endl;
    std::cout << "vender => Vender um Produto." << std::endl;
    std::cout << "comprar => Compror um Produto." << std::endl;
    std::cout << "sair => Sair do programa." << std::endl;
    std::cout << std::endl;
}

void InterfaceCLI::cadastrar()
{
}

void InterfaceCLI::editar()
{
}
void InterfaceCLI::buscar()
{
}

void InterfaceCLI::vender()
{
}

void InterfaceCLI::comprar()
{
}
} // namespace ivy
