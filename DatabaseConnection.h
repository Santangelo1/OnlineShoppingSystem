#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <iostream>
#include <string>

class DatabaseConnection
{
private:
    static DatabaseConnection *instance; // Singleton instance

    // Private constructor to prevent instantiation
    DatabaseConnection() {} //Private constructor

public:
    // Delete copy constructor and assignment operator to prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // Static method to get the singleton instance
    static DatabaseConnection *getInstance() {
        if  (!instance) {
            instance  = new DatabaseConnection();
        }
        return instance;
    }

    // Method to simulate a database connection
    void connect() {
        std::cout << "Connecting to the database..." << std::endl;
    }

   

    // Method to simulate data retrieval
    std::string fetchData(const std::string &query)
    {
        std::cout << "Executing query: " << query << std::endl;
        // Simulate data retrieval
        return "Sample Data";
    }
};

// Initialize static member
DatabaseConnection *DatabaseConnection::instance = nullptr;

#endif // DATABASE_CONNECTION_H