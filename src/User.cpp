#include "User.h"
#include <iostream>

// Constructor
User::User(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email)
    : id(id), username(username), password(password), name(name), email(email), loggedIn(false) {}

// Getters
int User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

bool User::isLoggedIn() const {
    return loggedIn;
}

// Setters
void User::setName(const std::string& name) {
    this->name = name;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

// Authentication Methods
bool User::login(const std::string& username, const std::string& password) {
    if (this->username == username && this->password == password) {
        loggedIn = true;
        std::cout << "Login successful for user: " << username << std::endl;
        return true;
    } else {
        std::cout << "Login failed: Invalid username or password" << std::endl;
        return false;
    }
}

void User::logout() {
    loggedIn = false;
    std::cout << "User " << username << " logged out." << std::endl;
}

// Display user profile
void User::displayProfile() const {
    std::cout << "User Profile:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Username: " << username << std::endl;
}

// Destructor
User::~User() {}
