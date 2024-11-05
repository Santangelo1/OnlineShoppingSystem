#include "Order.h"
#include <iostream>

int globalOrderId = 1;  // Global variable to keep track of order ID

// Constructor
Order::Order(int orderId, const std::string& userId, const std::vector<OrderItem>& items, const std::string& orderDate)
    : orderId(orderId), userId(userId), items(items), orderDate(orderDate) {
    calculateTotalAmount();
}

// Getters
int Order::getOrderId() const {
    return orderId;
}

std::string Order::getUserId() const {
    return userId;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

std::string Order::getOrderDate() const {
    return orderDate;
}

// Calculate total order amount
void Order::calculateTotalAmount() {
    totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.itemTotal;
    }
}

// Display order details
void Order::displayOrderDetails() const {
    std::cout << "Order ID: " << orderId << "\nUser ID: " << userId << "\nOrder Date: " << orderDate << std::endl;
    std::cout << "Items in Order:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.product.getName() << " | Quantity: " << item.quantity 
                  << " | Subtotal: $" << item.itemTotal << std::endl;
    }
    std::cout << "Total Amount: $" << totalAmount << std::endl;
}

// Static method to generate a unique order ID
int Order::generateOrderId() {
    return globalOrderId++;
}

// Destructor
Order::~Order() {}