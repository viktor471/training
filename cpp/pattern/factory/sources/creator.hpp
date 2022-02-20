#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "products.hpp"

class Creator{
public:
    virtual ~Creator(){}
    virtual Product* factoryMethod() const = 0;
    std::string operation() const;
};

class ConcreteCreator_1: public Creator{
public:
    Product* factoryMethod() const override;
};

class ConcreteCreator_2: public Creator{
public:
    Product* factoryMethod() const override;
};


#endif // FACTORY_HPP
