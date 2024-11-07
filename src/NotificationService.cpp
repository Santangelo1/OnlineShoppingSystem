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

//Method to send a notification message
void NotificationService::sendNotification(const std::string& message,
const std::string& type) const {
    if (type == "console") {
        std::cout << "Notification: " << message << std::endl;
    }

    //Future types (e.g. file logging or email) can be added here
    else if  (type == "file") {
        //Code for logging to a file (e.g., using ofstream)
    } else if  (type == "email") {
        //Code for sending email notifications
    } else {
        std::cerr << "Unknown notification type: " <<
        type <<  std::endl;
    }
    }

// Destructor
NotificationService::~NotificationService() {}
