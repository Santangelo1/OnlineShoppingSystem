#include "Inventory.h"

#include "DatabaseConnection.h"

// Initialize static members
std::unique_ptr<DatabaseConnection> DatabaseConnection::instance = nullptr;
std::mutex DatabaseConnection::mutex;

DatabaseConnection& DatabaseConnection::getInstance() {
    std::lock_guard<std::mutex> lock(mutex); // Thread safety
    if (!instance) {
        instance = std::make_unique<DatabaseConnection>();
    }
    return *instance;
}

void DatabaseConnection::connect() {
    try {
        // Add actual connection logic here
        std::cout << "Connecting to the database...\n";
    } catch (const std::exception& e) {
        std::cerr << "Error connecting to the database: " << e.what() << "\n";
    }
}

void DatabaseConnection::saveData(const std::string& data) {
    try {
        // Add actual data-saving logic here
        std::cout << "Saving data to the database: " << data << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error saving data: " << e.what() << "\n";
    }
}