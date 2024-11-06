#include <iostream>
#include <string>
#include <memory>
#include "Inventory.h" 
#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include "Cart.h"
#include "Order.h"
#include "Payment.h"

// Function declarations
void customerMenu(std::shared_ptr<Customer> customer, Inventory& inventory);
void adminMenu(std::shared_ptr<Admin> admin, Inventory& inventory);
std::shared_ptr<User> loginUser(const std::string& username, const std::string& password, Inventory& inventory);

int main() {
    Inventory inventory;

    // Load initial data from CSV files
    inventory.loadProductsFromFile("data/products.csv");  // Assume this function loads product data
    // Other data loading (users, orders) can be added here

    std::cout << "Welcome to the Online Shopping Cart System!" << std::endl;

    while (true) {
        std::string username, password;
        std::cout << "\nPlease log in:\n";
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        // Attempt to log in the user
        auto user = loginUser(username, password, inventory);

        if (user) {
            if (auto customer = std::dynamic_pointer_cast<Customer>(user)) {
                customerMenu(customer, inventory);
            } else if (auto admin = std::dynamic_pointer_cast<Admin>(user)) {
                adminMenu(admin, inventory);
            }
        } else {
            std::cout << "Invalid login credentials. Please try again.\n";
        }
    }

    return 0;
}

// Function to simulate user login and return a User object (Customer or Admin)
std::shared_ptr<User> loginUser(const std::string& username, const std::string& password, Inventory& inventory) {
    // Dummy data for testing. Replace with actual user loading and validation logic
    if (username == "customer" && password == "password") {
        return std::make_shared<Customer>(1, username, password, "John Doe", "john@example.com");
    } else if (username == "admin" && password == "adminpass") {
        return std::make_shared<Admin>(2, username, password, "Admin User", "admin@example.com");
    }
    return nullptr;
}

// Customer menu function
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
                inventory.listProducts();  // Display all products
                break;
            case 2: {
                int productId, quantity;
                std::cout << "Enter product ID to add: ";
                std::cin >> productId;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                
                auto product = inventory.findProductById(productId);
                if (product) {
                    cart.addProduct(*product, quantity);
                    std::cout << "Item added to cart.\n";
                } else {
                    std::cout << "Product not found.\n";
                }
                break;
            }
            case 3:
                cart.displayCart();  // Display cart contents
                break;
            case 4: {
                // Example checkout process
                double totalAmount = cart.calculateTotalCost();
                Payment payment(totalAmount, "Credit Card");  // Default to "Credit Card" for simplicity
                std::string paymentDetails;
                
                std::cout << "Enter payment details: ";
                std::cin.ignore();
                std::getline(std::cin, paymentDetails);
                
                if (payment.processPayment(paymentDetails)) {
                    std::cout << "Thank you for your purchase!\n";
                    customer->placeOrder();  // Add to order history
                    cart.clearCart();        // Clear cart after successful checkout
                }
                break;
            }
            case 5:
                return;  // Exit to main login menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Admin menu function
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
                std::cin.ignore();
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter category: ";
                std::getline(std::cin, category);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;

                inventory.addProduct(Product(id, name, description, price, quantity));
                std::cout << "Product added to inventory.\n";
                break;
            }
            case 3: {
                int id, quantity;
                std::string name, category, description;
                double price;

                std::cout << "Enter product ID to update: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter updated name: ";
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
                // Implement actual sales report logic here
                break;
            case 6:
                return;  // Exit to main login menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}