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

    void listProducts() const;                       // This can display products directly if needed
    const std::vector<Product>& getProducts() const; // New method to access products for other processing

    ~Inventory();
};

#endif // INVENTORY_H