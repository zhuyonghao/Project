/*
 *stat and manage
 *login
 *CRUD
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "menu.hpp"

class Administrator
{
public:
    Administrator(std::string USERNAME,
                  std::string PASSWORD) : userName(USERNAME), password(PASSWORD)
    {
        menu = Menu::getMenu();
    }

    void login() const;

    void manage() const;

    void SearchOrder() const;

    void ModifyOrder() const;

    void DeleteOrder() const;

    void SearchDishInfo() const;

    void AddDishInfo() const;

    void ModifyDishInfo() const;

    void DeleteDishInfo() const;

    void StatSale() const;

private:
    Menu *menu;
    std::string userName;
    std::string password;
};

void Administrator::login() const
{
    bool loginStatus = false;

    std::string USERNAME;
    std::string PASSWORD;

    std::cout << "userName: ";
    std::cin >> USERNAME;
    std::cout << "password: ";
    std::cin >> PASSWORD;

    if (USERNAME != userName)
        std::cout << "Incorrect username!\n";
    else if (USERNAME == userName && PASSWORD != password)
        std::cout << "Incorrect password!\n";
    else
    {
        std::cout << "Login succeeded!\n";
        loginStatus = true;
    }

    if (loginStatus)
        manage();
    else
        login();
}

void Administrator::manage() const
{
    bool isLoop = true;

    int selection = 0;

    std::cout << "\nPlease select an action:(0 to exit)\n"
              << "1. SearchOrder\n"
              << "2. ModifyOrder\n"
              << "3. DeleteOrder\n"
              << "4. SearchDishInfo\n"
              << "5. AddDishInfo\n"
              << "6. ModifyDishInfo\n"
              << "7. DeleteDishInfo\n"
              << "8. StatSale\n";

    std::cout << "Please enter a seletion: ";
    std::cin >> selection;

    switch (selection)
    {
    case 1:
        // SearchOrder();
        break;
    case 2:
        // ModifyOrder();
        break;
    case 3:
        // DeleteOrder();
        break;
    case 4:
        SearchDishInfo();
        break;
    case 5:
        AddDishInfo();
        break;
    case 6:
        ModifyDishInfo();
        break;
    case 7:
        DeleteDishInfo();
        break;
    case 8:
        StatSale();
        break;
    case 0:
        isLoop = false;
        break;
    default:
        std::cout << "Input Error!\n";
        break;
    }

    if (isLoop)
        manage();
}

void Administrator::SearchDishInfo() const
{
    int selection = 0;
    std::cout << "choose the way to search:\n";
    std::cout << "1. Search by number\n"
              << "2. Search by name\n";

    std::cout << "Please enter a seletion: ";
    std::cin >> selection;

    if (selection == 1)
    {
        size_t number;
        std::cout << "Please enter the dish number to search:\n"
                  << "number: ";
        std::cin >> number;

        auto it = std::find_if(menu->getDishInfo().begin(), menu->getDishInfo().end(),
                               [number](const DishInfo &obj)
                               { return obj.getNumber() == number; });

        if (it != menu->getDishInfo().end())
        {
            std::cout << "Found the dish " << number << std::endl
                      << std::endl;

            std::cout << "number" << '\t'
                      << "name" << '\t'
                      << "price" << '\t'
                      << "quantity" << '\t'
                      << "discount" << '\n';

            std::cout
                << it->getNumber() << '\t'
                << it->getName() << '\t'
                << it->getPrice() << '\t'
                << it->getQuantity() << '\t'
                << it->getDiscount() << '\n';
        }
        else
            std::cout << "Not found the dish " << number << std::endl;
    }

    else if (selection == 2)
    {
        std::string name;
        std::cout << "Please enter the dish name to search:\n"
                  << "name: ";
        std::cin >> name;

        auto it = std::find_if(menu->getDishInfo().begin(), menu->getDishInfo().end(),
                               [name](const DishInfo &obj)
                               { return obj.getName() == name; });

        if (it != menu->getDishInfo().end())
        {
            std::cout << "Found the dish " << name << std::endl
                      << std::endl;

            std::cout << "number" << '\t'
                      << "name" << '\t'
                      << "price" << '\t'
                      << "quantity" << '\t'
                      << "discount" << '\n';

            std::cout
                << it->getNumber() << '\t'
                << it->getName() << '\t'
                << it->getPrice() << '\t'
                << it->getQuantity() << '\t'
                << it->getDiscount() << '\n';
        }
        else
            std::cout << "Not found the dish " << name << std::endl;
    }

    else
    {
        std::cout << "Input Error!\n";
    }
}

void Administrator::AddDishInfo() const
{
    std::string name;
    double price;
    int quantity;
    double discount;

    std::cout << "Please enter the dish info to add:\n"
              << "name: ";
    std::cin >> name;
    std::cout << "price: ";
    std::cin >> price;
    std::cout << "quantity: ";
    std::cin >> quantity;
    std::cout << "discount: ";
    std::cin >> discount;

    DishInfo dishInfo(name, price, quantity, discount);

    menu->getDishInfo().push_back(dishInfo);

    std::cout << "Added successfully!\n";

    menu->outfileMenu();
}

void Administrator::ModifyDishInfo() const
{
    size_t number;
    std::string name;
    double price;
    int quantity;
    double discount;

    std::cout << "Please enter the dish number to modify:\n"
              << "number: ";
    std::cin >> number;

    auto it = std::find_if(menu->getDishInfo().begin(), menu->getDishInfo().end(),
                           [number](const DishInfo &obj)
                           { return obj.getNumber() == number; });

    if (it != menu->getDishInfo().end())
    {
        std::cout << "Found the dish " << number << std::endl
                  << std::endl;

        std::cout << "Please enter the dish info to modify:\n"
                  << "name: ";
        std::cin >> name;
        std::cout << "price: ";
        std::cin >> price;
        std::cout << "quantity: ";
        std::cin >> quantity;
        std::cout << "discount: ";
        std::cin >> discount;

        it->setName() = name;
        it->setPrice() = price;
        it->setQuantity() = quantity;
        it->setDiscount() = discount;

        std::cout << "Modified successfully!\n";

        menu->outfileMenu();
    }
    else
        std::cout << "Not found the dish " << number << std::endl;
}

void Administrator::DeleteDishInfo() const
{
    size_t number;

    std::cout << "Please enter the dish number to delete:\n"
              << "number: ";
    std::cin >> number;

    auto it = std::find_if(menu->getDishInfo().begin(), menu->getDishInfo().end(),
                           [number](const DishInfo &obj)
                           { return obj.getNumber() == number; });

    if (it != menu->getDishInfo().end())
    {
        std::cout << "Found the dish " << number << std::endl
                  << std::endl;

        menu->getDishInfo().erase(it);

        std::cout << "delete successfully!\n";

        menu->outfileMenu();
    }
    else
        std::cout << "Not found the dish " << number << std::endl;
}

void Administrator::StatSale() const
{
    menu->displayMenu();
}

#endif