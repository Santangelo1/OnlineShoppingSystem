#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int id;
    std::string username;
    std::string password;
    std::string name;
    std::string email;

public:
    // Constructor
    User(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email);

    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getName() const;
    std::string getEmail() const;

    // Login and Logout
    bool login(const std::string& password);
    void logout();

    // Destructor
    virtual ~User();
};

#endif // USER_H