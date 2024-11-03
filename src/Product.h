#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    int id;
    std::string name;
    double price;
    int quantity;
    bool isAvailable;

    Product(int id, const std::string& name, double price, int quantity);

    void display() const;
};

#endif