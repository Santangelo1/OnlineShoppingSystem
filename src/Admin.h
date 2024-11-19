#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "DatabaseConnection.h" 

class Admin {
public:
    Admin(int id, const std::string &username, const std::string &password,
          const std::string &name, const std::string &email);

    void loadAdminData();
    void saveAdminData(const std::string &adminData);
    void viewSalesReport();
    void manageProductCatalog();
    void handleCustomerQueries();

    void addProductToInventory(Inventory &inventory, const Product &product);
    void updateProductInInventory(Inventory &inventory, int productId, const std::string &name,
                                   const std::string &category, const std::string &description,
                                   double price, int quantity);
};

#endif // ADMIN_H
