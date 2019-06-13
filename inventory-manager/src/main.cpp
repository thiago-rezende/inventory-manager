#include "ivy/ivy.hpp"
#include "ivy/vetor/Vetor.hpp"

int main(int argc, char **argv)
{
    ivy::IvyManager *ivy = new ivy::IvyManager();

    ivy::Vetor v;

    v.adicionar(ivy::Produto());

    std::cout << v.get(0).get_nome() << std::endl;

    v.get(0).set_nome("MERDA");

    std::cout << v.get(0).get_nome() << std::endl;

    return 0;
}
