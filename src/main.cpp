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
#include <nana/paint/graphics.hpp>

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
        /**
         * @brief Criacao do form fm_init
         * @param make_center(1000x900)
         *
         */
        nana::form fm_init{nana::API::make_center(1000, 900)};

        /**
        * @brief Nome do ivymanager.exe
        *
        */
        fm_init.caption(("IvyManager"));

        /**
         * @brief Criacao do label cabecalho_ivy e estilizacao do texto 'IvyManager'
         * 
         */
        nana::label cabecalho_ivy{fm_init, ""};
        cabecalho_ivy.format(true);
        cabecalho_ivy.caption("<bold=true, color=0xff0000, font=\"Consolas\" size=18 center>IvyManager</>");
        cabecalho_ivy.text_align(nana::align::center, nana::align_v::center);

        /**
         * @brief Grupo geral grp_geral_principal
         *
         */
        nana::group grp_geral_principal{fm_init, "", true};

        /**
         * @brief Place plc_principal
         * 
         * @return nana::place 
         */
        nana::place plc_principal(fm_init);

        /**
         * @brief Divisao contento as dimensoes do cabecalho geral_principal e do grupo grp_geral_principal
         * @param 'vert gap=10 margin=5' colocando na vertical,espacamento de 10 e margem de 5
         * @param <lab_grupo weight=30> Separacao do geral_principal e grp_geral_principal
         * @param <todo> Para exibicao do grp_geral_principal,respeitando as condicoes de 'lab'
         * 
         */
        plc_principal.div("vert gap=10 margin=5 <lab_grupo weight=30><todo>");
        plc_principal["lab_grupo"] << cabecalho_ivy;
        plc_principal["todo"] << grp_geral_principal;

        /**
         * @brief Grupo de produtos(a esquerda), e grupo de botoes(a direta)
         * 
         */
        nana::group grp_tela_produto{grp_geral_principal, ("<bold=true, color=0xff0000, font=\"Consolas\">LISTA DE PRODUTOS:</>"), true};
        nana::group grp_btn_direita{grp_geral_principal, ("<bold=true, color=0xff0000, font=\"Consolas\">BOTOES:</>"), true};
        grp_geral_principal.div("horizontal gap=3 margin=20  < <tela_esquerda margin=20> | 30% <grupo_direita>> ");
        grp_geral_principal["tela_esquerda"] << grp_tela_produto;
        grp_geral_principal["grupo_direita"] << grp_btn_direita;

        grp_tela_produto.div("vert gap=5 margin=3");

        /* grp_btn_direita.div( "<vertical margin=2 gap= 2 <vert lab> | 40% < <left_field> | 70% <right_field>> >");*/
        /**
        * @brief Tela de cadastro,acionada assim que o btn_cadastrar for clicado
        * @param form fm_init
        *
        */
        fm_init.events().click([&fm_init] { //No momento nao foi implementado
            /**
             * @brief Criacao do form de cadastro
             *
             */
            nana::form fm_cadastro{nana::API::make_center(1000, 900)}, (fm_init);

            /**
             * @brief Nome da tela de cadastro
             *
             */
            fm_cadastro.caption(("IvyManager - Cadastrar"));

            /**
             * @brief Criacao dos textos de input : nome, marca, valor, Id e quantidade
             *
             */
            nana::textbox innome{fm_cadastro}, inmarca{fm_cadastro}, invalor{fm_cadastro}, inid{fm_cadastro}, inquantidade{fm_cadastro};

            /**
             * @brief Criacao dos botoes de enviar e cancelar o cadastro de produto
             *
             */
            nana::button env{fm_cadastro, "Enviar"}, cancel{fm_cadastro, "Cancelar"};

            /**
             * @brief Criacao dos botoes de buscar, editar, comprar ,vender
             *
             */
            nana::button buscar{fm_cadastro, "Buscar"}, editar{fm_cadastro, "Editar"}, comprar{fm_cadastro, "Comprar"}, vender{fm_cadastro, "Vender"};

            /**
             * @brief Criacao da escolha de garantia (Sim ou Nao)
             * 
             */
            nana::combox ingarantia(fm_cadastro, nana::rectangle(20, 3, 150, 30), "Garantia");

            /**
             * @brief Menu de escolha de garantia
             * 
             */
            ingarantia.caption(("Possui Garantia?"));
            ingarantia.push_back("Sim");
            ingarantia.push_back("Nao");

            /**
             * @brief Base para o Input dos dados de um novo produto
             * 
             */
            innome.tip_string("Nome:").multi_lines(false);
            inmarca.tip_string("Marca:").multi_lines(false);
            invalor.tip_string("Valor:").multi_lines(false);
            inid.tip_string("Id:").multi_lines(false);
            inquantidade.tip_string("Quantidade:").multi_lines(false);

            /**
             * @brief Base plc do form
             * 
             */
            nana::place plc{fm_cadastro};

            /**
             * @brief Cabecalho do Cadastro
             * 
             */
            nana::label input{fm_cadastro, ""};
            input.format(true);
            input.caption("<bold color=0x0080FF size=16 center>Cadastrar Produto</>");

            /**
             * @brief Grupo dos botoes buscar, editar, comprar e vender
             * 
             */
            nana::group buttons{fm_cadastro, "<bold=true, color=blue>Menu:</>", true};

            /**
             * @brief Divisao contento as dimensoes da interface de cadastro
             * @param <><weight=70% vertical<> Larguta da divisao
             * @param <weight=37% vertical> Deslocamento da altura entre o formulário e os botoes do grupo buttons
             * @param <vertical gap=10 textboxs arrange=[50,25,25,25,25,25,25]> Arrange determinando o tamanho de cada textbox dos input.
             *        Gap determinando a separação de cada input
             * @param <weight=40 gap=60 buttons> Tamanho. Separacao dos botoes de enviar e cancelar dos input de cadastro
             * @param <todo weight=70 margin=20 gap=10> Barra das opcoes de buscar, editar, comprar, vender
             * 
             */
            plc.div("<><weight=70% vertical<><weight=37% vertical <vertical gap=10 textboxs arrange=[50,25,25,25,25,25,25]> <weight=40 gap=60 buttons> ><todo weight=70 margin=20 gap=10><>><>");

            /**
             * @brief Coloca a barra "todo" na base plc
             * 
             */
            plc["todo"] << buscar << editar << comprar << vender;

            /**
             * @brief Coloca os input de produtos na base plc
             * 
             */
            plc.field("textboxs") << input << innome << inmarca << invalor << inid << inquantidade << ingarantia;

            /**
             * @brief Coloca os botoes de enviar e cancelar o input na base plc
             * 
             */
            plc.field("buttons") << env << cancel;
            /**
             * @brief Coloca o place plc
             * 
             */
            plc.collocate();

            /**
             * @brief Exibe o form fm
             * 
             */
            fm_init.show();

            /**
             * @brief fm_modal entra em rotina
             * 
             */
            fm_cadastro.modality();

            /**
             * @brief Constroi um novo nana::exec objeto
             * 
             */
        });
        plc_principal.collocate();
        fm_init.show();
        nana::exec();
    }

    return EXIT_SUCCESS;
}
