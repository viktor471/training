#include <iostream>

#include "client_code.hpp"

void clientCode(const Creator &creator) {
    std::cout   << "Client: I'm not aware of the creator "
                   "class, but it still works.\n"
                << creator.operation() << std::endl;
}
