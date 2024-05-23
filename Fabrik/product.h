
#ifndef FABRIK_PRODUCT_H
#define FABRIK_PRODUCT_H

#include <iostream>

class Product {

public:
    virtual ~Product() = default;
    virtual int getType() = 0;

};


class ProductA : public Product {

public:
    virtual ~ProductA() {
        std::cout << "Destructor Product A" << std::endl;
    }
    int getType() override;

};


class ProductB : public Product {

public:
    virtual ~ProductB() {
        std::cout << "Destructor Product B" << std::endl;
    }
    int getType() override;

};

#endif //FABRIK_PRODUCT_H
