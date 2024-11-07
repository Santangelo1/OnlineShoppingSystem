#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include "Inventory.h"
#include <string>

class NotificationService
{
public:
    // Constructor
    NotificationService();

    // Method to check if any product in the inventory is low on stock and notify the admin if so
    void checkLowStock(const Inventory &inventory, int threshold) const;

    // Method to send a notification message
    void sendNotification(const std::string &message) const;

    // Destructor
    ~NotificationService();
};

#endif // NOTIFICATION_SERVICE_H