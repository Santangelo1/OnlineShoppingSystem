#include "Inventory.h"
#include "Product.h"

class Admin {
public:
    Admin(int id, const std::string &username, const std::string &password,
          const std::string &name, const std::string &email);
    void addProductToInventory(Inventory &inventory, const Product &product);
    void updateProductInInventory(Inventory &inventory, int productId,
                                  const std::string &name, const std::string &category,
                                  const std::string &description, double price, int quantity);
    void removeProductFromInventory(Inventory &inventory, int productId);
    void viewSalesAnalytics(const SalesAnalytics &analytics) const;
    void setInventoryNotification(NotificationService &notificationService, const Inventory &inventory, int threshold) const;
    void generateRecommendations(const Inventory &inventory, const std::vector<int> &cartProductIds) const;
    void loadAdminData();
    void saveAdminData(const std::string& adminData);
    void viewSalesReport();
    void manageProductCatalog();
    void handleCustomerQueries();
    ~Admin();
};


Admin::Admin(int id, const std::string &username, const std::string &password,
             const std::string &name, const std::string &email) {
    // Initialize admin attributes (if any are defined in the Admin class)
    std::cout << "Admin created: " << name << " (ID: " << id << ")\n";
    


void Admin::addProductToInventory(Inventory &inventory, const Product &product) {
    inventory.addProduct(product);
    std::cout << "Product added to inventory.\n";
}

void Admin::updateProductInInventory(Inventory &inventory, int productId,
                                     const std::string &name, const std::string &category,
                                     const std::string &description, double price, int quantity) {
    if (inventory.updateProduct(productId, name, category, description, price, quantity)) {
        std::cout << "Product updated successfully.\n";
    } else {
        std::cout << "Failed to update product.\n";
    }
}















void Admin::loadAdminData() {
    DatabaseConnection* db = DatabaseConnection::getInstance();
    db->connect();
    std::string data = db->fetchData("SELECT * FROM admins");
    std::cout << "Loaded admin data: " << data << "\n";
}

void Admin::saveAdminData(const std::string& adminData) {
    DatabaseConnection* db = DatabaseConnection::getInstance();
    db->saveData(adminData);
    std::cout << "Admin data saved to the database.\n";
}

void Admin::viewSalesReport() {
    std::cout << "Viewing sales report...\n";
    // Logic to view and generate sales report
}

void Admin::manageProductCatalog() {
    std::cout << "Managing product catalog...\n";
    // Logic to add, update, or remove products
}

void Admin::handleCustomerQueries() {
    std::cout << "Handling customer queries...\n";
    // Logic to handle customer support or queries
}


// Constructor
Admin::Admin(int id, const std::string &username, const std::string &password, const std::string &name, const std::string &email)
    : User(id, username, password, name, email) {}

// Add a product to inventory
void Admin::addProductToInventory(Inventory &inventory, const Product &product)
{
    inventory.addProduct(product);
    std::cout << "Product added to inventory.\n";
}

// Update a product in inventory
void Admin::updateProductInInventory(Inventory &inventory, int productId, const std::string &name, const std::string &category,
                                     const std::string &description, double price, int quantity)
{
    if (inventory.updateProduct(productId, name, category, description, price, quantity))
    {
        std::cout << "Product updated successfully.\n";
    }
    else
    {
        std::cout << "Failed to update product. Product ID not found.\n";
    }
}

// Remove a product from inventory
void Admin::removeProductFromInventory(Inventory &inventory, int productId)
{
    if (inventory.deleteProduct(productId))
    {
        std::cout << "Product removed from inventory.\n";
    }
    else
    {
        std::cout << "Failed to remove product. Product ID not found.\n";
    }
}

// View sales analytics
void Admin::viewSalesAnalytics(const SalesAnalytics &analytics) const
{
    analytics.displaySalesSummary();
    analytics.displayProductSalesReport();
}

// Set real-time inventory notifications
void Admin::setInventoryNotification(NotificationService &notificationService, const Inventory &inventory, int threshold) const
{
    notificationService.checkLowStock(inventory, threshold);
}

// Generate recommendations based on items in the cart
void Admin::generateRecommendations(const Inventory &inventory, const std::vector<int> &cartProductIds) const
{
    std::cout << "Recommended products based on your cart:\n";
    for (const auto &productId : cartProductIds)
    {
        auto recommendedProducts = inventory.getRelatedProducts(productId);
        for (const auto &recommendedProduct : recommendedProducts)
        {
            std::cout << "- " << recommendedProduct.getName() << " ($" << recommendedProduct.getPrice() << ")\n";
        }
    }
}

// Destructor
Admin::~Admin() {}