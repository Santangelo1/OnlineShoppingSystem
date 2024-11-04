#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;                      // Unique identifier for the user
    std::string username;        // Username for login
    std::string password;        // Password for login
    std::string name;            // Full name of the user
    std::string email;           // Email address
    bool loggedIn;               // Status to check if the user is logged in

public:
    // Constructor
    User(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email);

    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getName() const;
    std::string getEmail() const;
    bool isLoggedIn() const;

    // Setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);

    // Authentication Methods
    bool login(const std::string& username, const std::string& password);  // Log in user
    void logout();                                                         // Log out user

    // Display user profile
    void displayProfile() const;

    // Destructor
    ~User();
};

#endif // USER_H
