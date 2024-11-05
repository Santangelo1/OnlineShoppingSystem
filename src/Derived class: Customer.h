#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Cart.h"  // Ensure this file exists and contains the definition of the Cart class
// Ensure Cart.h contains the definition of the Cart class
#include "Order.h"
#include <vector>

class Customer : public User {
private:
    Cart cart;                        // Customer's cart
    std::vector<Order> orderHistory;  // Order history

public:
    // Constructor
    Customer(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email);

    // Cart and Order Management
    void addToCart(const Product& product, int quantity);
    void placeOrder();
    void viewOrderHistory() const;

    // Destructor
    ~Customer();
};

#endif // CUSTOMER_H