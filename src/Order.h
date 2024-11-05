#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include "Cart.h"
#include <string>
#include <vector>

struct OrderItem {
    Product product;
    int quantity;
    double itemTotal;

    OrderItem(const Product& product, int quantity)
        : product(product), quantity(quantity), itemTotal(product.getPrice() * quantity) {}
};

class Order {
private:
    int orderId;                              // Unique order ID
    std::string userId;                       // ID of the user who placed the order
    std::vector<OrderItem> items;             // List of items in the order
    double totalAmount;                       // Total order amount
    std::string orderDate;                    // Order date (string format for simplicity)

public:
    // Constructor
    Order(int orderId, const std::string& userId, const std::vector<OrderItem>& items, const std::string& orderDate);

    // Getters
    int getOrderId() const;
    std::string getUserId() const;
    double getTotalAmount() const;
    std::string getOrderDate() const;

    // Order Management
    void calculateTotalAmount();
    void displayOrderDetails() const;
    
    // Static method for generating order ID
    static int generateOrderId();

    // Destructor
    ~Order();
};

#endif // ORDER_H