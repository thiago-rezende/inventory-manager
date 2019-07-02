#include "LocadoraCLI.hpp"

namespace ivy
{
namespace locadora
{

LocadoraCLI::LocadoraCLI(Locadora &nLocadora)
{
    this->m_locadora = nLocadora;
    this->sair = false;
}

LocadoraCLI::~LocadoraCLI()
{
}

void LocadoraCLI::run()
{
    this->logo();

    /* Looping principal */
    while (!this->sair)
    {
        this->menu();
        this->option_handler();
    }
    this->sair = false;
}

void LocadoraCLI::logo()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << R"( _                         _                 )" << std::endl;
    std::cout << R"(| |                       | |                )" << std::endl;
    std::cout << R"(| |     ___   ___ __ _  __| | ___  _ __ __ _ )" << std::endl;
    std::cout << R"(| |    / _ \ / __/ _` |/ _` |/ _ \| '__/ _` |)" << std::endl;
    std::cout << R"(| |___| (_) | (_| (_| | (_| | (_) | | | (_| |)" << std::endl;
    std::cout << R"(\_____/\___/ \___\__,_|\__,_|\___/|_|  \__,_|)" << std::endl;
    std::cout << R"(                                             )" << std::endl;
    std::cout << R"(                                             )" << std::endl;
    std::cout << std::endl;

    //std::cout << "Pressione enter para iniciar ..." << std::endl;
    //std::cin.get();
}

void LocadoraCLI::menu()
{
    std::cout << "Locadora > ";

    std::getline(std::cin, this->opt);
    /* Transforma a opcao entrada em letras minusculas */
    std::transform(this->opt.begin(), this->opt.end(), this->opt.begin(), ::tolower);
    std::cout << std::endl;
}

void LocadoraCLI::option_handler()
{
    if (this->opt == "ajuda")
        this->ajuda();
    else if (this->opt == "cadastrar")
        this->cadastrar();
    else if (this->opt == "editar")
        this->editar();
    else if (this->opt == "buscar")
        this->buscar();
    else if (this->opt == "alugar")
        this->alugar();
    else if (this->opt == "devolver")
        this->devolver();
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

void LocadoraCLI::ajuda()
{
    std::cout << std::endl;
    std::cout << "Comandos: " << std::endl;
    std::cout << "  ajuda => Exibe os comandos disponiveis." << std::endl;
    std::cout << "  cadastrar => Cadastrar um novo Jogo." << std::endl;
    std::cout << "  editar => Editar um Jogo." << std::endl;
    std::cout << "  buscar => Buscar um Jogo." << std::endl;
    std::cout << "  alugar => Alugar um Jogo." << std::endl;
    std::cout << "  devolver => Devolver um Jogo." << std::endl;
    std::cout << "  salvar => Salva o estoque em um arquivo." << std::endl;
    std::cout << "  carregar => Carrega o estoque de um arquivo." << std::endl;
    std::cout << "  sair => Sair da locadora." << std::endl;
    std::cout << std::endl;
}

void LocadoraCLI::cadastrar()
{
    std::cout << std::endl;
    Jogo nJogo;

    std::string nNome;
    std::string nGenero;
    std::string str_nDisponivel;
    int nId, nFaixaEtaria;
    float nValor;
    bool nDisponivel;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cin.ignore();
    std::cout << "Nome do Jogo: ";
    std::getline(std::cin, nNome);
    std::cout << "Genero do Jogo: ";
    std::getline(std::cin, nGenero);
    std::cout << "Valor do Jogo: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nValor))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    std::cout << "Faixa etaria do Jogo: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nFaixaEtaria))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }

    std::cin.ignore();
    std::cout << "Jogo disponivel [sim/nao]: ";
    std::getline(std::cin, str_nDisponivel);
    std::transform(str_nDisponivel.begin(), str_nDisponivel.end(), str_nDisponivel.begin(), ::tolower);
    if (str_nDisponivel == "sim")
        nDisponivel = true;
    else
        nDisponivel = false;

    nJogo.set_jogoID(nId);
    nJogo.set_nome(nNome);
    nJogo.set_genero(nGenero);
    nJogo.set_valor(nValor);
    nJogo.set_faixaEtaria(nFaixaEtaria);
    nJogo.set_disponivel(nDisponivel);

    this->m_locadora.cadastrar(nJogo);
    std::cout << std::endl;
}

void LocadoraCLI::editar()
{
    std::cout << std::endl;
    Jogo nJogo;

    std::string nNome;
    std::string nGenero;
    std::string str_nDisponivel;
    int nId, nFaixaEtaria;
    float nValor;
    bool nDisponivel;

    std::cout << "Nome do Jogo: ";
    std::getline(std::cin, nNome);

    if (this->m_locadora.buscar_nome(nNome) == -1)
    {
        IVY_WARN("EDITAR::Jogo_NAO_ENCONTRADO");
        std::cout << "EDITAR::Jogo_NAO_ENCONTRADO" << std::endl;
    }
    else
    {

        nId = this->m_locadora.get_estoque().get(this->m_locadora.buscar_nome(nNome)).get_jogoID();

        std::cout << "Descreva o novo Jogo." << std::endl;
        std::cin.ignore();
        std::cout << "Nome do Jogo: ";
        std::getline(std::cin, nNome);
        std::cout << "Genero do Jogo: ";
        std::getline(std::cin, nGenero);
        std::cout << "Valor do Jogo: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nValor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cout << "Faixa etaria do Jogo: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nFaixaEtaria))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }

        std::cin.ignore();
        std::cout << "Jogo disponivel [sim/nao]: ";
        std::getline(std::cin, str_nDisponivel);
        std::transform(str_nDisponivel.begin(), str_nDisponivel.end(), str_nDisponivel.begin(), ::tolower);
        if (str_nDisponivel == "sim")
            nDisponivel = true;
        else
            nDisponivel = false;

        nJogo.set_jogoID(nId);
        nJogo.set_nome(nNome);
        nJogo.set_genero(nGenero);
        nJogo.set_valor(nValor);
        nJogo.set_faixaEtaria(nFaixaEtaria);
        nJogo.set_disponivel(nDisponivel);

        this->m_locadora.editar(nId, nJogo);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void LocadoraCLI::buscar()
{
    std::cout << std::endl;

    std::string str_busca;

    while (true)
    {
        std::cout << "Buscar por [genero/alugado/classificacao]: ";
        std::getline(std::cin, str_busca);
        /* Transforma a opcao entrada em letras minusculas */
        std::transform(str_busca.begin(), str_busca.end(), str_busca.begin(), ::tolower);
        if (str_busca != "genero" && str_busca != "alugado" && str_busca != "classificacao")
            continue;
        else
            break;
    }
    if (str_busca == "genero")
    {
        std::string nGenero;
        std::cout << "Informe a genero: ";
        std::getline(std::cin, nGenero);
        int index = this->m_locadora.buscar_genero(nGenero);
        if (index != -1)
            std::cout << this->m_locadora.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::Jogo_NAO_ENCONTRADO" << std::endl;
    }
    else if (str_busca == "alugado")
    {
        std::string str_nDisponivel;
        bool nDisponivel;

        std::cout << "Jogo disponivel [sim/nao]: ";
        std::getline(std::cin, str_nDisponivel);
        std::transform(str_nDisponivel.begin(), str_nDisponivel.end(), str_nDisponivel.begin(), ::tolower);
        if (str_nDisponivel == "sim")
            nDisponivel = false;
        else
            nDisponivel = true;

        int index = this->m_locadora.buscar_alugado(nDisponivel);
        if (index != -1)
            std::cout << this->m_locadora.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::Jogo_NAO_ENCONTRADO" << std::endl;
    }
    else if (str_busca == "classificacao")
    {
        int nFaixaEtaria;
        std::cout << "Informe a faixa etaria: ";
        /* Checa se a entrada e valida */
        while (!(std::cin >> nFaixaEtaria))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Somente numeros!" << std::endl;
        }
        std::cin.ignore();
        int index = this->m_locadora.buscar_faixaEtaria(nFaixaEtaria);
        if (index != -1)
            std::cout << this->m_locadora.get_estoque().get(index).to_string() << std::endl;
        else
            std::cout << "BUSCA::Jogo_NAO_ENCONTRADO" << std::endl;
    }

    std::cout << std::endl;
}

void LocadoraCLI::alugar()
{
    std::cout << std::endl;

    int nId;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }

    this->m_locadora.alugar(nId);

    std::cout << std::endl;
}

void LocadoraCLI::devolver()
{
    std::cout << std::endl;

    int nId;

    std::cout << "Numero de identificacao: ";
    /* Checa se a entrada e valida */
    while (!(std::cin >> nId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Somente numeros!" << std::endl;
    }
    this->m_locadora.devolver(nId);
    std::cout << std::endl;
}

void LocadoraCLI::salvar()
{
    m_locadora.salvar_estoque();
}

void LocadoraCLI::carregar()
{
    m_locadora.carregar_estoque();
}
} // namespace locadora
} // namespace ivy