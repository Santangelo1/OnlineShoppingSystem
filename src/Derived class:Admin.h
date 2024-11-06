#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Inventory.h"
#include "../path/to/SalesAnalytics.h" // Update the path to the correct location of SalesAnalytics.h

class Admin : public User {
public:
    // Constructor
    Admin(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email);

    // Inventory Management
    void addProductToInventory(Inventory& inventory, const Product& product);
    void removeProductFromInventory(Inventory& inventory, int productId);
    void viewSalesAnalytics(SalesAnalytics& analytics) const;

    // Destructor
    ~Admin();
};

#endif // ADMIN_H