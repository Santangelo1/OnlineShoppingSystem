#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Product> products; //Collection of products in inventory

public:
    //Constructor
    Inventory();

    //Inventory Management Methods
    void addProduct(const Product& product);    //Add a new product to inventory
    bool removeProduct(int productid);         // Remove product from inventory by ID
    Product* findProductById(int productId);  //Find product by ID
    std::vector<Product> findProductsByName(const std::string& name); //Find products by name
    bool updateStock(int productId, int quantity);  //Update stock of a product
    void displayAllProducts() const;          //Displays all products in inventory


    //Getter for the products vector  (read-only)

    //Destructor
    ~Inventory();
};

#endif


    
