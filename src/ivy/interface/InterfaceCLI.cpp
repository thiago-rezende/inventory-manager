#include "InterfaceCLI.hpp"

namespace ivy
{
InterfaceCLI::InterfaceCLI(IvyManager &nIvy_manager)
{
    this->ivy_manager = nIvy_manager;
    this->sair = false;
}

InterfaceCLI::~InterfaceCLI()
{
}

void InterfaceCLI::run()
{
    this->logo();

    /* Looping principal */
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
    /* Transforma a opcao entrada em letras minusculas */
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
    else if (this->opt == "salvar")
        this->salvar();
    else if (this->opt == "carregar")
        this->carregar();
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
    std::cout << "  ajuda => Exibe os comandos disponiveis." << std::endl;
    std::cout << "  cadastrar => Cadastrar um novo Produto." << std::endl;
    std::cout << "  editar => Editar um Produto." << std::endl;
    std::cout << "  buscar => Buscar um Produto." << std::endl;
    std::cout << "  vender => Vender um Produto." << std::endl;
    std::cout << "  comprar => Compror um Produto." << std::endl;
    std::cout << "  salvar => Salva o estoque em um arquivo." << std::endl;
    std::cout << "  carregar => Carrega o estoque de um arquivo." << std::endl;
    std::cout << "  sair => Sair do programa." << std::endl;
    std::cout << std::endl;
}

void InterfaceCLI::cadastrar()
{
    std::cout << std::endl;
    Produto nProduto;

    std::string nNome;
    std::string nMarca;
    std::string str_nGarantia;
    int nId;
    float nValor;
    int nQuantidade;
    bool nGarantia;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cin.ignore();
    std::cout << "Nome do Produto: ";
    std::getline(std::cin, nNome);
    std::cout << "Marca do Produto: ";
    std::getline(std::cin, nMarca);
    std::cout << "Valor do Produto: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nValor))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cout << "Quantidade do Produto: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nQuantidade))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cin.ignore();
    std::cout << "Garantia do Produto [sim/nao]: ";
    std::getline(std::cin, str_nGarantia);
    std::transform(str_nGarantia.begin(), str_nGarantia.end(), str_nGarantia.begin(), ::tolower);
    if (str_nGarantia == "sim")
        nGarantia = true;
    else
        nGarantia = false;

    nProduto.set_id(nId);
    nProduto.set_nome(nNome);
    nProduto.set_marca(nMarca);
    nProduto.set_valor(nValor);
    nProduto.set_quantidade(nQuantidade);
    nProduto.set_garantia(nGarantia);

    this->ivy_manager.cadastrar(nProduto);
    std::cout << std::endl;
}

void InterfaceCLI::editar()
{
    std::cout << std::endl;
    Produto nProduto;

    std::string nNome;
    std::string nMarca;
    std::string str_nGarantia;
    int nId;
    float nValor;
    int nQuantidade;
    bool nGarantia;

    std::cout << "Nome do Produto: ";
    std::getline(std::cin, nNome);

    if (this->ivy_manager.buscar_nome(nNome) == -1)
    {
        IVY_WARN("EDITAR::PRODUTO_NAO_ENCONTRADO");
        std::cout << "EDITAR::PRODUTO_NAO_ENCONTRADO" << std::endl;
    }
    else
    {

        nId = this->ivy_manager.get_estoque().get(this->ivy_manager.buscar_nome(nNome)).get_id();

        std::cout << "Descreva o novo produto." << std::endl;
        std::cout << "Nome do Produto: ";
        std::cin.ignore();
        std::getline(std::cin, nNome);
        std::cout << "Marca do Produto: ";
        std::getline(std::cin, nMarca);
        std::cout << "Valor do Produto: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nValor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cout << "Quantidade do Produto: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nQuantidade))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cin.ignore();
        std::cout << "Garantia do Produto [sim/nao]: ";
        std::getline(std::cin, str_nGarantia);
        std::transform(str_nGarantia.begin(), str_nGarantia.end(), str_nGarantia.begin(), ::tolower);
        if (str_nGarantia == "sim")
            nGarantia = true;
        else
            nGarantia = false;

        nProduto.set_id(nId);
        nProduto.set_nome(nNome);
        nProduto.set_marca(nMarca);
        nProduto.set_valor(nValor);
        nProduto.set_quantidade(nQuantidade);
        nProduto.set_garantia(nGarantia);

        this->ivy_manager.editar(nId, nProduto);
    }
    std::cout << std::endl;
}

void InterfaceCLI::buscar()
{
    std::cout << std::endl;

    std::string str_busca;

    while (true)
    {
        std::cout << "Buscar por [marca/valor/quantidade]: ";
        std::getline(std::cin, str_busca);
        /* Transforma a opcao entrada em letras minusculas */
        std::transform(str_busca.begin(), str_busca.end(), str_busca.begin(), ::tolower);
        if (str_busca != "marca" && str_busca != "valor" && str_busca != "quantidade")
            continue;
        else
            break;
    }
    if (str_busca == "marca")
    {
        std::string nMarca;
        std::cout << "Informe a marca: ";
        std::getline(std::cin, nMarca);
        int index = this->ivy_manager.buscar_marca(nMarca);
        if (index != -1)
            std::cout << this->ivy_manager.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
    }
    else if (str_busca == "valor")
    {
        float nValor;
        std::cout << "Informe o valor: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nValor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cin.ignore();
        int index = this->ivy_manager.buscar_valor(nValor);
        if (index != -1)
            std::cout << this->ivy_manager.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
    }
    else if (str_busca == "quantidade")
    {
        int nQuantidade;
        std::cout << "Informe a quantidade: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nQuantidade))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cin.ignore();
        int index = this->ivy_manager.buscar_quantidade(nQuantidade);
        if (index != -1)
            std::cout << this->ivy_manager.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::PRODUTO_NAO_ENCONTRADO" << std::endl;
    }

    std::cout << std::endl;
}

void InterfaceCLI::vender()
{
    std::cout << std::endl;

    int nId, nQuantidade;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cout << "Quantidade: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nQuantidade))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cin.ignore();
    this->ivy_manager.vender(nId, nQuantidade);

    std::cout << std::endl;
}

void InterfaceCLI::comprar()
{
    std::cout << std::endl;

    int nId, nQuantidade;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cout << "Quantidade: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nQuantidade))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cin.ignore();
    this->ivy_manager.comprar(nId, nQuantidade);
    std::cout << std::endl;
}

void InterfaceCLI::salvar()
{
    ivy_manager.salvar_estoque();
}

void InterfaceCLI::carregar()
{
    ivy_manager.carregar_estoque();
}
} // namespace ivy
