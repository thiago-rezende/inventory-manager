#include "ivy/ivy.hpp"
#include "ivy/vetor/Vetor.hpp"

int main(int argc, char **argv)
{
    ivy::IvyManager *ivy = new ivy::IvyManager();

    ivy::Vetor v;

    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());
    v.adicionar(ivy::Produto());

    v.get(0).set_nome("MERDA");

    std::cout << "Tamanho: " << v.get_tamanho() << std::endl;

    v.remover(2);

    for (int i = 0; i < v.get_tamanho(); i++)
        std::cout << v.get(i).get_nome() << std::endl;

    std::cout << "Tamanho: " << v.get_tamanho() << std::endl;

    v.adicionar(ivy::Produto());

    std::cout << "Tamanho: " << v.get_tamanho() << std::endl;

    return 0;
}
