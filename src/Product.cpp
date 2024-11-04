#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, const std::string& category,
                 const std::string& description, double price, int quantity)
    : id(id), name(name), category(category), description(description), 
      price(price), quantity(quantity), isAvailable(true) {}

void Product::display() const {
    std::cout << "Product ID: " << id 
              << ", Name: " << name 
              << ", Category: " << category 
              << ", Price: $" << price 
              << ", Quantity: " << quantity 
              << ", Available: " << (isAvailable ? "Yes" : "No") << '\n';
}

void Product::setAvailability(bool available) {
    isAvailable = available;
}