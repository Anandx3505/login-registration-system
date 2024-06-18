#ifndef AUTHSERVICE_HPP
#define AUTHSERVICE_HPP

#include <vector>
#include "User.hpp"
#include "FileHandler.hpp"

class AuthService {
private:
    std::vector<User> users;
    FileHandler fileHandler;

    std::string hashPassword(const std::string& password);

public:
    AuthService();
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
};

#endif // AUTHSERVICE_HPP
