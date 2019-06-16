#include "ivy/ivy.hpp"

int main(int argc, char **argv)
{
    ivy::IvyManager ivy;

    ivy::InterfaceCLI cli(&ivy);

    cli.run();

    return 0;
}
