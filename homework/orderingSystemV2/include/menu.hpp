/*
 *save in file form
 *displayMenu
 *
 */
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "dishInfo.hpp"

class Menu
{
public:
    static Menu *getMenu();

    void displayMenu();

    void outfileMenu();

    // declare as a reference before modification
    std::vector<DishInfo> &getDishInfo() { return menu; }

private:
    static Menu *MENU;
    Menu() {}
    std::vector<DishInfo> menu;
};

Menu *Menu::MENU = nullptr;

Menu *Menu::getMenu()
{
    if (MENU == nullptr)
        MENU = new Menu();
    return MENU;
}

void Menu::displayMenu()
{
    std::cout << "\nnumber" << '\t'
              << "name" << '\t'
              << "price" << '\t'
              << "quantity" << '\t'
              << "discount" << '\n';

    for (const DishInfo &dishInfo : menu)
        std::cout
            << dishInfo.getNumber() << "\t"
            << dishInfo.getName() << "\t"
            << dishInfo.getPrice() << "\t"
            << dishInfo.getQuantity() << "\t\t"
            << dishInfo.getDiscount() << '\n';
    std::cout << "\n\n";
}

void Menu::outfileMenu()
{
    std::ofstream outFile("menu.txt");

    if (!outFile)
    {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }

    outFile << "number" << '\t'
            << "name" << '\t'
            << "price" << '\t'
            << "quantity" << '\t'
            << "discount" << '\n';

    for (const DishInfo &dishInfo : menu)
    {
        outFile
            << dishInfo.getNumber() << "\t\t"
            << dishInfo.getName() << "\t\t"
            << dishInfo.getPrice() << "\t\t"
            << dishInfo.getQuantity() << "\t\t\t"
            << dishInfo.getDiscount() << "\n";
    }

    std::cout << "Successful operation!\n";
}

#endif