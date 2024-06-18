#include "User.hpp"

User::User(const std::string& username, const std::string& passwordHash)
    : username(username), passwordHash(passwordHash) {}

const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPasswordHash() const {
    return passwordHash;
}
