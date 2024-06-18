#include "Menu.hpp"
#include <iostream>

void Menu::displayMenu() {
    int choice;
    std::string username, password;

    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                authService.registerUser(username, password);
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                authService.loginUser(username, password);
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
