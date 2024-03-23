/*
 *judge
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include "administrator.hpp"
#include "customer.hpp"

class UserInterface
{
public:
    UserInterface(std::string userName = "",
                  std::string password = "",
                  std::string customerName = "") : administrator(userName, password), customer(customerName) {}
    void determineIdentity();

private:
    Administrator administrator;
    Customer customer;
};

void UserInterface::determineIdentity()
{
    int serialNumber;

    while (true)
    {
        std::cout << "Please select the serial number to confirm your identity(0 to exit)\n";
        std::cout << "1. administrator\t2. customer\n";
        std::cout << "Enter your selection: ";
        std::cin >> serialNumber;

        if (serialNumber == 1)
            administrator.login();
        else if (serialNumber == 2)
            customer.orderFood();
        else if (serialNumber == 0)
            break;
        else
            std::cout << "Input Error\n";
    }
}

#endif