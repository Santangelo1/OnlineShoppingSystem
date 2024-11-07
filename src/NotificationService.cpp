#include "NotificationService.h"
#include <iostream>

// Constructor
NotificationService::NotificationService() {}

// Method to check for low stock in the inventory
void NotificationService::checkLowStock(const Inventory &inventory, int threshold) const
{
    for (const auto &product : inventory.getProducts())
    { // Assuming `getProducts` returns a vector of all products
        if (product.getStockQuantity() <= threshold)
        {
            std::string message = "Low stock alert: " + product.getName() + " (ID: " + std::to_string(product.getId()) +
                                  ") is running low. Only " + std::to_string(product.getStockQuantity()) + " left in stock.";
            sendNotification(message);
        }
    }
}

// Method to send notification message (prints to console for demonstration)
void NotificationService::sendNotification(const std::string &message) const
{
    std::cout << "Notification: " << message << std::endl;
}

// Destructor
NotificationService::~NotificationService() {}