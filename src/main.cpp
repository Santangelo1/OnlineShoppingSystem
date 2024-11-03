#include <iostream>
#include <string>
#include <memory>
#include "Inventory.h"
#include "User.h"
#include "Cart.h"
#include "Order.h"
#include "Payment.h"

// Function declarations
void customerMenu(std::shared_ptr<Customer> customer, Inventory& inventory);
void adminMenu(std::shared_ptr<Admin> admin, Inventory& inventory);
std::shared_ptr<User> loginUser(const std::string& username, const std::string& password, Inventory& inventory);

int main() {
    Inventory inventory;

    // Load initial data (e.g., from CSV files)
    inventory.loadProducts("data/products.csv");
    // Additional loading can go here (e.g., loading users, orders)

    std::cout << "Welcome to the Online Shopping Cart System!" << std::endl;

    while (true) {
        std::string username, password;
        std::cout << "\nPlease log in:\n";
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        auto user = loginUser(username, password, inventory);

        if (user) {
            if (auto customer = std::dynamic_pointer_cast<Customer>(user)) {
                customerMenu(customer, inventory);
            } else if (auto admin = std::dynamic_pointer_cast<Admin>(user)) {
                adminMenu(admin, inventory);
            }
        } else {
            std::cout << "Invalid login credentials. Please try again." << std::endl;
        }
    }

    return 0;
}

// Function to simulate user login and return a User object
std::shared_ptr<User> loginUser(const std::string& username, const std::string& password, Inventory& inventory) {
    // For simplicity, we're assuming the login is directly matched with hardcoded users
    if (username == "customer1" && password == "password") {
        return std::make_shared<Customer>(username, password);
    } else if (username == "admin" && password == "adminpass") {
        return std::make_shared<Admin>(username, password);
    }
    return nullptr; // Login failed
}

// Customer menu
void customerMenu(std::shared_ptr<Customer> customer, Inventory& inventory) {
    Cart cart;
    int choice;

    while (true) {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "1. View Product Catalog\n";
        std::cout << "2. Add Item to Cart\n";
        std::cout << "3. View Cart\n";
        std::cout << "4. Checkout\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory.listProducts();
                break;
            case 2: {
                int productId, quantity;
                std::cout << "Enter product ID to add: ";
                std::cin >> productId;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                auto product = inventory.findProduct(productId);
                if (product) {
                    cart.addProduct(productId, quantity);
                    std::cout << "Item added to cart.\n";
                } else {
                    std::cout << "Product not found.\n";
                }
                break;
            }
            case 3:
                cart.viewCart();
                break;
            case 4: {
                CreditCardPayment payment;
                double totalAmount = 100.0; // Assume a total for demonstration
                payment.processPayment(totalAmount);
                std::cout << "Thank you for your purchase!\n";
                return; // Exit to main login menu after checkout
            }
            case 5:
                return; // Logout
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Admin menu
void adminMenu(std::shared_ptr<Admin> admin, Inventory& inventory) {
    int choice;

    while (true) {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. View Inventory\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Update Product\n";
        std::cout << "4. Delete Product\n";
        std::cout << "5. View Sales Reports\n";
        std::cout << "6. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory.listProducts();
                break;
            case 2: {
                int id, quantity;
                std::string name, category, description;
                double price;
                std::cout << "Enter product ID: ";
                std::cin >> id;
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter category: ";
                std::getline(std::cin, category);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                inventory.addProduct(id, name, category, description, price, quantity);
                std::cout << "Product added to inventory.\n";
                break;
            }
            case 3: {
                int id, quantity;
                std::string name, category, description;
                double price;
                std::cout << "Enter product ID to update: ";
                std::cin >> id;
                std::cout << "Enter updated name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter updated category: ";
                std::getline(std::cin, category);
                std::cout << "Enter updated description: ";
                std::getline(std::cin, description);
                std::cout << "Enter updated price: ";
                std::cin >> price;
                std::cout << "Enter updated quantity: ";
                std::cin >> quantity;
                inventory.updateProduct(id, name, category, description, price, quantity);
                std::cout << "Product updated.\n";
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter product ID to delete: ";
                std::cin >> id;
                inventory.deleteProduct(id);
                std::cout << "Product deleted from inventory.\n";
                break;
            }
            case 5:
                std::cout << "Displaying sales reports...\n";
                // Implement sales report functionality
                break;
            case 6:
                return; // Logout
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}