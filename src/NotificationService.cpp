#include "NotificationService.h"
#include <iostream>

// Constructor
NotificationService::NotificationService() {}

// Method to check for low stock in the inventory
void NotificationService::checkLowStock(const Inventory &inventory, int threshold) const
{
    // Access products via getProducts
    for (const auto &product : inventory.getProducts())
    {
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