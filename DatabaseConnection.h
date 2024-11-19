#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <mutex> // For thread safety

class DatabaseConnection {
public:
    // Singleton getter
    static DatabaseConnection& getInstance();

    // Connect to the database
    void connect();

    // Save data to the database
    void saveData(const std::string& data);

private:
    // Private constructor and destructor to prevent instantiation
    DatabaseConnection() = default;
    ~DatabaseConnection() = default;

    // Delete copy constructor and assignment operator to prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // Static instance of the singleton
    static std::unique_ptr<DatabaseConnection> instance;
    static std::mutex mutex; // For thread safety
};

#endif // DATABASE_CONNECTION_H
