#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
#include <unordered_map>

class Cart {
private:
    // Store products in the cart with their quantities
    std::unordered_map<int, int> productQuantities; // Map product ID to quantity
    std::vector<Product> products;                  // List of products in the cart

    // Helper function to find a product by ID
    Product* findProductById(int productId);

public:
    // Constructor
    Cart();

    // Cart Management Methods
    bool addProduct(const Product& product, int quantity); // Add product to cart
    bool removeProduct(int productId);                     // Remove product from cart
    bool updateProductQuantity(int productId, int quantity); // Update product quantity in cart
    double calculateTotalCost() const;                     // Calculate total cost of products in cart
    void displayCart() const;                              // Display all items in cart

    // Clear cart
    void clearCart();

    // Destructor
    ~Cart();
};

#endif // CART_H