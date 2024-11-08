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

    Product *findProductById(int productId); // Add this line

    std::vector<Product> findProductsByName(const std::string &name) const;

    bool updateStock(int productId, int quantity);

    void displayAllProducts() const;

    const std::vector<Product> &listProducts() const;

    ~Inventory();
};

#endif // INVENTORY_H