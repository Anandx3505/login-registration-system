#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <vector>
#include "User.hpp"

class FileHandler {
private:
    const std::string filename = "users.txt";

public:
    std::vector<User> readUsersFromFile();
    void saveUsersToFile(const std::vector<User>& users);
};

#endif // FILEHANDLER_HPP
