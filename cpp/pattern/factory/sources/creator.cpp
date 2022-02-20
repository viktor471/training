#include "creator.hpp"

std::string Creator::operation() const{
    Product* product = this->factoryMethod();

    std::string result = "Creator: the same creator's code has"
                             "just worked with " + product->operation();
    delete product;
    return result;
}

Product *ConcreteCreator_1::factoryMethod() const{
    return new ConcreteProduct_1();
}

Product *ConcreteCreator_2::factoryMethod() const{
    return new ConcreteProduct_2();
}
