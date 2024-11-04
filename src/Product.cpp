#include "Product.h"
#include <iostream>

// Constructor
Product::Product(int id, const std::string& name, const std::string& description, double price, int stockQuantity)
    : id(id), name(name), description(description), price(price), stockQuantity(stockQuantity) {}

// Getters
int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

std::string Product::getDescription() const {
    return description;
}

double Product::getPrice() const {
    return price;
}

int Product::getStockQuantity() const {
    return stockQuantity;
}

// Setters
void Product::setPrice(double price) {
    this->price = price;
}

void Product::setStockQuantity(int stock) {
    this->stockQuantity = stock;
}

// Business Logic Methods
bool Product::isInStock() const {
    return stockQuantity > 0;
}

void Product::displayProduct() const {
    std::cout << "Product ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Stock: " << stockQuantity << " units" << std::endl;
}

bool Product::reduceStock(int quantity) {
    if (stockQuantity >= quantity) {
        stockQuantity -= quantity;
        return true;
    } else {
        std::cout << "Insufficient stock for product: " << name << std::endl;
        return false;
    }
}

// Destructor
Product::~Product() {}