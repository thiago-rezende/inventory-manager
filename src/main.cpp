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
         * @brief Criacao do form fm abrindo a tela inicialmente com 1000x900
         * 
         */
        nana::form fm{nana::API::make_center(1000, 900)};

        /**
         * @brief Nome do ivymanager.exe
         * 
         */
        fm.caption(("IvyManager"));

        /**
         * @brief Criacao dos textos de input : nome, marca, valor, Id e quantidade
         * 
         */
        nana::textbox innome{fm}, inmarca{fm}, invalor{fm}, inid{fm}, inquantidade{fm};

        /**
         * @brief Criacao dos botoes de enviar e cancelar o cadastro de produto
         * 
         */
        nana::button env{fm, "Enviar"}, cancel{fm, "Cancelar"};

        /**
         * @brief Criacao dos botoes de buscar, editar, comprar ,vender
         * 
         */
        nana::button buscar{fm, "Buscar"}, editar{fm, "Editar"}, comprar{fm, "Comprar"}, vender{fm, "Vender"};

        /**
         * @brief Criacao da escolha de garantia (Sim ou Nao)
         * 
         */
        nana::combox ingarantia(fm, nana::rectangle(20, 3, 150, 30), "Garantia");

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
        nana::place plc{fm};

        /**
         * @brief Cabecalho do Cadastro
         * 
         */
        nana::label input{fm, ""};
        input.format(true);
        input.caption("<bold color=0x0080FF size=16 center>Cadastrar Produto</>");

        /**
         * @brief Grupo dos botoes buscar, editar, comprar e vender
         * 
         */
        nana::group buttons{fm, "<bold=true, color=blue>Menu:</>", true};

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
        fm.show();

        /**
         * @brief Busca a imagem de fundo na pasta res
         * 
         */
        nana::paint::image img("res/background.bmp");

        /**
         * @brief Chama a funcao de desenhar
         * 
         * @return nana::drawing 
         */
        nana::drawing dw(fm);

        /**
         * @brief Pega a imagem de fundo e coloca no dw
         * @param Grafico graph
         * 
         */
        dw.draw([&img](nana::paint::graphics &graph) {
            if (img.empty())
            {
                std::cout << "IMAGEM DE FUNDO NAO EXISTE!" << std::endl;
                return;
            }
            img.paste(graph, nana::point{});
        });

        /**
         * @brief Mostra a imagem de fundo
         * 
         */
        dw.update();

        /**
         * @brief Constroi um novo nana::exec objeto
         * 
         */
        nana::exec();
    }

    return EXIT_SUCCESS;
}
