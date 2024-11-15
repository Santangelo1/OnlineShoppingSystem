#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <memory>
#include <iostream>
#include <stdexcept>

class DatabaseConnection {
public:
    static std::unique_ptr<DatabaseConnection> instance;

    static DatabaseConnection& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<DatabaseConnection>(new DatabaseConnection());
        }
        return *instance;
    }

    void connect() {
        try {
            // Add actual connection logic here
            std::cout << "Connecting to the database...\n";
        } catch (const std::exception& e) {
            std::cerr << "Error connecting to the database: " << e.what() << "\n";
        }
    }

    void saveData() {
        try {
            // Add actual data saving logic here
            std::cout << "Saving data to the database...\n";
        } catch (const std::exception& e) {
            std::cerr << "Error saving data: " << e.what() << "\n";
        }
    }

private:
    DatabaseConnection() = default;
    ~DatabaseConnection() = default;
};

// Initialize the static instance to nullptr
std::unique_ptr<DatabaseConnection> DatabaseConnection::instance = nullptr;

#endif // DATABASE_CONNECTION_H