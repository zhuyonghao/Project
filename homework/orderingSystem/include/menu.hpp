/*
 *save in file form
 *displayMenu
 *
 */
#ifndef MENU_H
#define MENU_H

#include <string>

static size_t number = 1;

class Menu
{
public:
    Menu(
        std::string NAME,
        double PRICE,
        int QUANTITY,
        double DISCOUNT);

    ~Menu()
    {
        --number;
    }

    void outfileMenu(std::string fileName);
    void displayMenu();

private:
    size_t number;
    std::string name;
    double price;
    int quantity;
    double discount;
};

Menu::Menu(
    std::string NAME,
    double PRICE,
    int QUANTITY,
    double DISCOUNT) : name(NAME), price(PRICE), quantity(QUANTITY), discount(DISCOUNT)
{
    ++number;
}

#endif