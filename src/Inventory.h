#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>

class Inventory
{
private:
    std::vector<Product> products;

public:
    Inventory();

    void addProduct(const Product &product);
    bool deleteProduct(int productId);
    bool updateProduct(int productId, const std::string &name, const std::string &category,
    const std::string &description, double price, int quantity);

//New version of listProducts that returns a reference to the product vector
 const std::vector<Product>& listProducts() const; 

    ~Inventory();
};

#endif // INVENTORY_H