#include <cli/cli.hpp>
#include "ivy/ivy.hpp"

#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/label.hpp>

int main(int argc, const char **argv)
{
    ivy::IvyLog::init();

    IVY_WARN("Why are you {}?", "RUNNING");

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
        nana::form fm{nana::API::make_center(1000, 900)};

        /* fm.bgcolor(colors::mint_cream ); */
        nana::place plc(fm);
        std::vector<std::unique_ptr<nana::button>> btns;

        /* the most external widgets */
        nana::label out{fm, "This label is out of any group"};
        nana::group ext_gr{fm, "An external <bold=true, color=blue>Group:</>", true};
        plc.div("vert gap=20 margin=180 <lab weight=30><all> ");
        plc["lab"] << out;
        plc["all"] << ext_gr;

        /* the external group contain: */
        nana::group grp_left{ext_gr, ("A new <bold=true, color=0xff0000, font=\"Consolas\">Group:</>"), true};
        nana::group grp_right{ext_gr, ("A right <bold=true, color=0xff0000, font=\"Consolas\">Group:</>"), true};
        ext_gr.div("horizontal gap=3 margin=20  < <left_field> | 70% <right_field>> ");
        ext_gr["left_field"] << grp_left;
        ext_gr["right_field"] << grp_right;

        /* the left group */
        grp_left.div("buttons vert gap=5 margin=3");

        /* the right group */
        nana::group nested(grp_right.handle());
        nana::label lab{grp_right, "A simple label "};
        nana::button b1{grp_right, "Adicionar Botao"};
        b1.events().click([&grp_left, &btns] {
            btns.emplace_back(new nana::button(grp_left, "Button"));
            grp_left["buttons"] << *btns.back();
            grp_left.collocate();
            std::cout << "Botao adicionado!\n";
        });
        nana::button b2{grp_right, "Botao => 2"};
        nana::button b3{grp_right, "Botao => 3"};
        grp_right.div("<vertical margin=2 gap= 2 <vert lab> | 40% < <left_field> | 70% <right_field>> >");
        grp_right["lab"] << lab.text_align(nana::align::right) << nested;
        grp_right["left_field"] << b1;
        grp_right["right_field"] << b2 << b3;

        /* the nested (rigth up) group */
        nana::label lab1{nested, "A very simple group:"};
        nana::button b4{nested, "Botao => 4"};
        nana::button b5{nested, "Botao => 5"};
        nana::button b6{nested, "Botao => 6"};
        nested.div(" margin=3 min=30 gap= 2 all");
        nested["all"] << lab1 << b4 << b5 << b6;
        plc.collocate();
        /* grp1.plc.collocate(); */
        fm.show();

        nana::paint::image img("res/background.bmp");
        nana::drawing dw(fm);
        dw.draw([&img](nana::paint::graphics &graph) {
            if (img.empty())
            {
                std::cout << "IMAGEM DE FUNDO NÃO EXISTE!" << std::endl;
                return;
            }
            img.paste(graph, nana::point{});
        });
        dw.update();
        nana::exec();
    }

    return EXIT_SUCCESS;
}
