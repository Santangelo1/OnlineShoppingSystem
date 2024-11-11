#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <iostream>
#include <string>

class DatabaseConnection {
    private:
    //Static instance for Singleton pattern
    static DatabaseConnection *instance; 

    // Private constructor to prevent instantiation from outside
    DatabaseConnection() {} 

public:
    // Delete copy constructor and assignment operator to prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // Static method to get the singleton instance of DatabaseConnection
    static DatabaseConnection *getInstance() {
        if  (!instance) {
            instance  = new DatabaseConnection();
        }
        return instance;
    }

    // Simulate a method to connect to the  database 
    void connect() {
        std::cout << "Connecting to the database..." << std::endl;
    }
       

std::string fetchData(const std::string&  query) {
    std::cout << "Executing query: " << query << std::endl;
    return "Sample Data for query: " + query;
   }
};


#endif // DATABASE_CONNECTION_H