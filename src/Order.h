#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include <string>
#include <vector>

class OrderItem {
private:
    Product product;
    int quantity;
    double itemTotal;

public:
    OrderItem(const Product& product, int quantity)
        : product(product), quantity(quantity), itemTotal(product.getPrice() * quantity) {}

    // Getters
    Product getProduct() const { return product; }
    int getQuantity() const { return quantity; }
    double getItemTotal() const { return itemTotal; }
};

class Order {
private:
    int orderId;
    std::string userId;
    std::vector<OrderItem> items;
    double totalAmount;
    std::string orderDate;

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
