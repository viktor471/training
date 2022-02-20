#include <string>

class Product{
public:
    virtual ~Product() = default;
    virtual std::string operation() const = 0;
};

class ConcreteProduct_1 : public Product{
public:
    std::string operation() const override;
};

class ConcreteProduct_2 : public Product{
public:
    std::string operation() const override;
};

