#include <cli/cli.hpp>
#include "ivy/ivy.hpp"

#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/scroll.hpp>
#include <nana/paint/graphics.hpp>
#include <nana/gui/widgets/listbox.hpp>

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
        ivy::IvyManager ivy;
        ivy::InterfaceCLI cli(ivy);
        cli.run();
    }
    else
    {
        std::cout << "\nA Interface GUI ainda esta em desenvolvimento.\n\n"
                  << "Precione enter para contuar com a Inteface CLI..." << std::endl;

        std::cin.get();

        ivy::IvyManager ivy;
        ivy::InterfaceCLI cli(ivy);
        cli.run();

        /* ivy::InterfaceGUI gui(1080, 480, "Ivy - Inventory Manager");
        gui.run(); */
    }

    return EXIT_SUCCESS;
}
