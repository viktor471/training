#include <iostream>

#include "client_code.hpp"

int main()
{
    std::cout << "App launched with the ConcreteCreator_1. \n\n";

    Creator* creator_1 = new ConcreteCreator_1();
    clientCode(*creator_1);

    std::cout << "\n\n\n"
              << "App launched with the ConcreteCreator_2. \n\n";

    Creator* creator_2 = new ConcreteCreator_2();
    clientCode(*creator_2);

    delete creator_1;
    delete creator_2;

    return 0;
}
