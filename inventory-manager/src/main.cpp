#include "ivy/ivy.hpp"
#include "ivy/produto/Produto.hpp"
#include "ivy/vetor/Vetor.hpp"

int main(int argc, char **argv)
{
    ivy::IvyManager *ivy = new ivy::IvyManager();

    ivy::Vetor<ivy::Produto> v;

    v.adicionar(ivy::Produto());

    std::cout << v.get(0).get_nome() << std::endl;

    delete ivy;

    return 0;
}
