#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;                       // Unique identifier for the product
    std::string name;             // Name of the product
    std::string description;      // Description of the product
    double price;                 // Price of the product
    int stockQuantity;            // Available stock of the product

public:
    // Constructor
    Product(int id, const std::string& name, const std::string& description, double price, int stockQuantity);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getStockQuantity() const;

    // Setters
    void setPrice(double price);
    void setStockQuantity(int stock);

    // Business Logic Methods
    bool isInStock() const;                  // Check if product is in stock
    void displayProduct() const;             // Display product details
    bool reduceStock(int quantity);          // Reduce stock by a given quantity

    // Destructor
    ~Product();
};

#endif // PRODUCT_H