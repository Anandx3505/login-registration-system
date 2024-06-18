#include "AuthService.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional> // for std::hash

AuthService::AuthService() {
    users = fileHandler.readUsersFromFile();
}

std::string AuthService::hashPassword(const std::string& password) {
    size_t seed = 0;
    for (char c : password) {
        seed ^= std::hash<char>{}(c) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << seed;
    return ss.str();
}

bool AuthService::registerUser(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.getUsername() == username;
    });

    if (it != users.end()) {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
        return false;
    }

    std::string hashedPassword = hashPassword(password);
    users.emplace_back(username, hashedPassword);
    fileHandler.saveUsersToFile(users);
    std::cout << "User registered successfully." << std::endl;
    return true;
}

bool AuthService::loginUser(const std::string& username, const std::string& password) {
    std::string hashedPassword = hashPassword(password);
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.getUsername() == username && user.getPasswordHash() == hashedPassword;
    });

    if (it != users.end()) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Incorrect username or password. Please try again." << std::endl;
        return false;
    }
}
