#include <cli/cli.hpp>
#include "ivy/ivy.hpp"

int main(int argc, const char **argv)
{
    ivy::IvyLog::init();

    IVY_INFO("Ivy - Inventory Manager");

    cli::Parser parser(argc, argv);

    bool use_cli = parser.flag("cli")
                       .alias("cli")
                       .description("Run Ivy Manager in CLI mode")
                       .getValue();

    if (parser.hasErrors())
        return EXIT_FAILURE;

    if (use_cli)
    {
        ivy::IvyManager ivy_manager;
        ivy::locadora::Locadora ivy_locadora;
        ivy::InterfaceCLI cli(ivy_manager, ivy_locadora);
        cli.run();
    }
    else
    {
        IVY_INFO("A InterfaceGUI foi desativada para a correcao de uma falha critica");
        IVY_INFO("Novas versoes serao disponibilizadas no repositorio do projeto no GitHub");
        std::cout << "\nPrecione enter para contuar com a Inteface CLI..." << std::endl;

        std::cin.get();

        ivy::IvyManager ivy_manager;
        ivy::locadora::Locadora ivy_locadora;
        ivy::InterfaceCLI cli(ivy_manager, ivy_locadora);
        cli.run();

        /* ivy::InterfaceGUI gui(1080, 480, "Ivy - Inventory Manager");
        gui.run(); */
    }

    return EXIT_SUCCESS;
}
