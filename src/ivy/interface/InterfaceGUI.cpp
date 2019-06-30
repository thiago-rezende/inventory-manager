#include "InterfaceGUI.hpp"

namespace ivy
{
InterfaceGUI::InterfaceGUI(unsigned int nScreenWidth, unsigned int nScreenHeight, std::string nTitel)
    : m_screenWidth(nScreenWidth), m_screenHeight(nScreenHeight), m_title(nTitel)
{
}

InterfaceGUI::~InterfaceGUI()
{
}

void InterfaceGUI::run()
{
    nana::form fm_init{nana::API::make_center(m_screenWidth, m_screenHeight)};

    fm_init.caption((m_title));

    nana::label cabecalho_ivy{fm_init, ""};
    cabecalho_ivy.format(true);
    cabecalho_ivy.caption("<bold=true, color=0xff0000, font=\"Consolas\" size=18 center>IvyManager</>");
    cabecalho_ivy.text_align(nana::align::center, nana::align_v::center);

    nana::group grp_geral_principal{fm_init, "", true};

    nana::place plc_principal(fm_init);

    plc_principal.div("vert gap=10 margin=5 <lab_grupo weight=30><todo>");
    plc_principal["lab_grupo"] << cabecalho_ivy;
    plc_principal["todo"] << grp_geral_principal;

    nana::group grp_tela_produto{grp_geral_principal, ("<bold=true, color=0xff0000, font=\"Consolas\">LISTA DE PRODUTOS:</>"), true};
    nana::group grp_btn_direita{grp_geral_principal, ("<bold=true, color=0xff0000, font=\"Consolas\">BOTOES:</>"), true};

    nana::button btn_cadastrar{grp_btn_direita, "Cadastrar"};
    nana::button btn_buscar{grp_btn_direita, "Buscar"};
    nana::button btn_editar{grp_btn_direita, "Editar"};
    nana::button btn_salvar{grp_btn_direita, "Salvar"};
    nana::button btn_atualizar{grp_btn_direita, "Atualizar"};

    grp_geral_principal.div("gap=3 margin=20 < <vert tela_esquerda> | 25% <vert grupo_direita>> ");
    grp_geral_principal["tela_esquerda"] << grp_tela_produto;
    grp_geral_principal["grupo_direita"] << grp_btn_direita;
    grp_tela_produto.div("vert gap=5 margin=3");

    grp_btn_direita.div("vertical gap=5<vert botoes_vertical arrange=[70,70,70] margin=20 gap=15> <botoes_horizontal weight=100 margin=20 gap=10>");
    grp_btn_direita["botoes_vertical"] << btn_cadastrar << btn_buscar << btn_editar;
    grp_btn_direita["botoes_horizontal"] << btn_salvar << btn_atualizar;

    nana::listbox tabela{grp_tela_produto};
    tabela.append_header("ID");
    tabela.append_header("Nome");
    tabela.append_header("Marca");
    tabela.append_header("Valor");
    tabela.append_header("Quantidade");
    tabela.append_header("Garantia");

    grp_tela_produto.div("<tabela>");
    grp_tela_produto["tabela"] << tabela;

    btn_cadastrar.events().click([&fm_init, &tabela, this] {
        nana::inputbox::integer nId("ID", 0, 0, 10000, 1);
        nana::inputbox::text nNome("Nome");
        nana::inputbox::text nMarca("Marca");
        nana::inputbox::real nValor("Valor", 0, 0, 10000, 0.5);
        nana::inputbox::integer nQuantidade("Quantidade", 0, 0, 1000, 1);
        nana::inputbox::text nGarantia("Garantia", std::vector<std::string>{"Sim", "Nao"});

        nana::inputbox inbox(fm_init, "Preencha as informacoes do <bold>Produto</>.", "Cadastrar Produto");

        //Sets a verifier
        inbox.verify([&](nana::window handle) {
            if (nNome.value().empty() || nMarca.value().empty())
            {
                nana::msgbox mb(handle, "Entrada Invalida");
                mb << "Preencha todos os campos.";
                mb.show();
                return false; //verification failed
            }
            return true; //verified successfully
        });

        if (inbox.show(nId, nNome, nMarca, nValor, nQuantidade, nGarantia))
        {
            m_ivyManager.cadastrar(Produto(nId.value(), nNome.value(), nMarca.value(), nValor.value(), nQuantidade.value(), (nGarantia.value() == "Sim" ? true : false)));
            tabela.auto_draw(false);
            tabela.at(0).append({std::to_string(nId.value()),
                                 nNome.value(),
                                 nMarca.value(),
                                 std::to_string(nValor.value()),
                                 std::to_string(nQuantidade.value()),
                                 nGarantia.value()});
            tabela.auto_draw(true);
        }
    });

    btn_buscar.events().click([&] {
        nana::inputbox::text nTipoBusca("Buscar por", std::vector<std::string>{"Marca", "Valor", "Quantidade"});

        nana::inputbox inbox(fm_init, "Buscar por <bold>[Marca, Valor, Quantidade]</>.", "Buscar Produto");

        //Sets a verifier
        inbox.verify([&](nana::window handle) {
            return true; //verified successfully
        });

        if (inbox.show(nTipoBusca))
        {
        }
    });

    btn_editar.events().click([&] {
        nana::inputbox::integer nIdBusca("ID", 0, 0, 10000, 1);

        nana::inputbox inbox(fm_init, "Editar <bold>Produto</>.", "Editar Produto");

        //Sets a verifier
        inbox.verify([&](nana::window handle) {
            IVY_INFO("Selected id: {}", nIdBusca.value());
            if (this->m_ivyManager.buscar_id(nIdBusca.value()) < 0)
            {
                nana::msgbox mb(handle, "Entrada Invalida");
                mb << "Produto nao encontrado.";
                mb.show();
                return false; //verification failed
            }
            return true; //verified successfully
        });

        if (inbox.show(nIdBusca))
        {
            nana::inputbox::integer nId("ID", 0, 0, 10000, 1);
            nana::inputbox::text nNome("Nome");
            nana::inputbox::text nMarca("Marca");
            nana::inputbox::real nValor("Valor", 0, 0, 10000, 0.5);
            nana::inputbox::integer nQuantidade("Quantidade", 0, 0, 1000, 1);
            nana::inputbox::text nGarantia("Garantia", std::vector<std::string>{"Sim", "Nao"});

            nana::inputbox nInbox(inbox);

            //Sets a verifier
            nInbox.verify([&](nana::window nHandle) {
                if (nNome.value().empty() || nMarca.value().empty())
                {
                    nana::msgbox mb(nHandle, "Entrada Invalida");
                    mb << "Preencha todos os campos.";
                    mb.show();
                    return false; //verification failed
                }
                return true; //verified successfully
            });

            if (nInbox.show(nId, nNome, nMarca, nValor, nQuantidade, nGarantia))
            {
                m_ivyManager.editar(nIdBusca.value(), Produto(nId.value(), nNome.value(), nMarca.value(), nValor.value(), nQuantidade.value(), (nGarantia.value() == "Sim" ? true : false)));
                auto estoque = m_ivyManager.get_estoque();
                tabela.clear();
                tabela.auto_draw(false);
                for (int i = 0; i < estoque.get_tamanho(); i++)
                {
                    tabela.at(0).append({std::to_string(estoque.get(i).get_id()),
                                         estoque.get(i).get_nome(),
                                         estoque.get(i).get_marca(),
                                         std::to_string(estoque.get(i).get_valor()),
                                         std::to_string(estoque.get(i).get_quantidade()),
                                         (estoque.get(i).get_garantia() == true ? "Sim" : "Nao")});
                }
                tabela.auto_draw(true);
            }
        }
    });

    btn_salvar.events().click([&] {
        IVY_INFO(std::to_string(m_ivyManager.get_estoque().get_tamanho()));
    });

    plc_principal.collocate();
    fm_init.show();
    nana::exec();
}

} // namespace ivy
