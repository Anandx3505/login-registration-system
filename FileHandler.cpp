#include "FileHandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<User> FileHandler::readUsersFromFile() {
    std::vector<User> users;
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "No existing users file found." << std::endl;
        return users;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string username, passwordHash;
        iss >> username >> passwordHash;
        users.emplace_back(username, passwordHash);
    }

    inFile.close();
    return users;
}

void FileHandler::saveUsersToFile(const std::vector<User>& users) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error saving users to file." << std::endl;
        return;
    }

    for (const auto& user : users) {
        outFile << user.getUsername() << " " << user.getPasswordHash() << std::endl;
    }

    outFile.close();
}
