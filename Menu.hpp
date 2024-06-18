#ifndef MENU_HPP
#define MENU_HPP

#include "AuthService.hpp"

class Menu {
private:
    AuthService authService;

public:
    void displayMenu();
};

#endif // MENU_HPP
