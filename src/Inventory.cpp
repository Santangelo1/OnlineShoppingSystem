#include "Inventory.h"
#include <iostream>

// Constructor
Inventory::Inventory() {}

// Add a new product to inventory
void Inventory::addProduct(const Product& product) {
    products.push_back(product);
    std::cout << "Product added: " << product.getName() << std::endl;
}

// Remove product by ID
bool Inventory::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            products.erase(it);
            std::cout << "Product removed with ID: " << productId << std::endl;
            return true;
        }
    }
    std::cout << "Product with ID " << productId << " not found." << std::endl;
    return false;
}

// Find product by ID
Product* Inventory::findProductById(int productId) {
    for (auto& product : products) {
        if (product.getId() == productId) {
            return &product;
        }
    }
    std::cout << "Product with ID " << productId << " not found." << std::endl;
    return nullptr;
}

// Find products by name (partial match allowed)
std::vector<Product> Inventory::findProductsByName(const std::string& name) {
    std::vector<Product> matchingProducts;
    for (const auto& product : products) {
        if (product.getName().find(name) != std::string::npos) {
            matchingProducts.push_back(product);
        }
    }
    return matchingProducts;
}

// Update stock of a product
bool Inventory::updateStock(int productId, int quantity) {
    Product* product = findProductById(productId);
    if (product) {
        product->setStockQuantity(quantity);
        std::cout << "Stock updated for product ID " << productId << " to " << quantity << " units." << std::endl;
        return true;
    }
    std::cout << "Product with ID " << productId << " not found. Cannot update stock." << std::endl;
    return false;
}

// Display all products in inventory
void Inventory::displayAllProducts() const {
    std::cout << "Inventory List:" << std::endl;
    for (const auto& product : products) {
        product.displayProduct();
        std::cout << "-----------------------------" << std::endl;
    }
}

// Getter for the products vector (read-only)
const std::vector<Product>& Inventory::getProducts() const {
    return products;
}

// Destructor
Inventory::~Inventory() {}