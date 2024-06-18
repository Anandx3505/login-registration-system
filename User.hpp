#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
private:
    std::string username;
    std::string passwordHash;

public:
    User(const std::string& username, const std::string& passwordHash);

    const std::string& getUsername() const;
    const std::string& getPasswordHash() const;
};

#endif // USER_HPP
