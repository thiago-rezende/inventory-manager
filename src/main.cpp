#include "ivy/ivy.hpp"

#include <nana/gui/wvl.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

int main(int argc, char **argv)
{
    /* ivy::IvyManager ivy;
    ivy::InterfaceCLI cli(ivy);
    cli.run(); */

    /* Define widgets */
    nana::form fm;
    nana::textbox usr{fm}, pswd{fm};
    nana::button login{fm, "Login"}, cancel{fm, "Cancel"};

    login.events().click([&fm] {
        std::cout << "Button Clicked!" << std::endl;
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

    return 0;
}
