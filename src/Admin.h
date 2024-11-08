#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Inventory.h"
#include "SalesAnalytics.h"
#include "NotificationService.h" 
#include <string>

class Admin : public User
{
public:
    // Constructor
    Admin(int id, const std::string &username, const std::string &password, const std::string &name, const std::string &email);

    // Inventory Management
    void addProductToInventory(Inventory &inventory, const Product &product);
    void updateProductInInventory(Inventory &inventory, int productId, const std::string &name, const std::string &category,
                                  const std::string &description, double price, int quantity);
    void removeProductFromInventory(Inventory &inventory, int productId);

    // Sales Analytics
    void viewSalesAnalytics(const SalesAnalytics &analytics) const;

    // Real-Time Notifications
    void setInventoryNotification(NotificationService &notificationService, const Inventory &inventory, int threshold) const;

    // Recommendations
    void generateRecommendations(const Inventory &inventory, const std::vector<int> &cartProductIds) const;

    // Destructor
    ~Admin();
};

#endif // ADMIN_H
