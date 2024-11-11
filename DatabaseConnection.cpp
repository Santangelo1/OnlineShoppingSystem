#include "Inventory.h"
#include "DatabaseConnection.h"

void Inventory::loadInventoryData()
{
    DatabaseConnection *db = DatabaseConnection::getInstance();
    db->connect();
    std::string data = db->fetchData("SELECT * FROM inventory");
    // Process `data` to populate inventory...
    std::cout << "Loaded inventory data: " << data << std::endl;
}