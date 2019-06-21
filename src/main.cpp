#include "ivy/cli/cli.hpp"
#include "ivy/ivy.hpp"

#include <nana/gui/wvl.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

int main(int argc, const char **argv)
{
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
        /* Define widgets */
        nana::form fm{nana::API::make_center(300, 200)};
        nana::textbox usr{fm}, pswd{fm};
        nana::button login{fm, "Login"}, cancel{fm, "Cancel"};

        login.events().click([&usr, &pswd]() {
            std::string usr_str;
            std::string usr_pswd;
            usr.getline(0, usr_str);
            pswd.getline(0, usr_pswd);
            nana::msgbox m("Hello");
            m << usr_str << "\n"
              << usr_pswd;
            m();
        });

        cancel.events().click([&fm] {
            fm.close();
        });

        usr.tip_string("User:").multi_lines(false);
        pswd.tip_string("Password:").multi_lines(false).mask('*');

        /* Define a place for the form. */
        nana::place plc{fm};

        /* Divide the form into fields */
        plc.div("<><weight=80% vertical<><weight=70% vertical <vertical gap=10 textboxes arrange=[25,25]>  <weight=25 gap=10 buttons> ><>><>");

        /* Insert widgets */

        /* The field textboxes is vertical. It automatically adjusts the widgets' top and height attributes. */
        plc.field("textboxes") << usr << pswd;

        plc["buttons"] << login << cancel;

        /* Finially, the widgets should be collocated.
        Do not miss this line! Otherwise, the widgets will not be collocated
        until the form is resized. */
        plc.collocate();

        fm.show();
        nana::exec();
    }

    return EXIT_SUCCESS;
}
