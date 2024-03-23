/*
 *menu and order both have in common
 */

#ifndef DISHINFO_H
#define DISHINFO_H

#include <string>

class DishInfo
{
public:
    DishInfo(
        std::string NAME,
        double PRICE,
        int QUANTITY,
        double DISCOUNT);

    // setValue

    std::string &setName() { return name; }

    double &setPrice() { return price; }

    int &setQuantity() { return quantity; }

    double &setDiscount() { return discount; }
    // getValue
    size_t getNumber() const { return number; }

    std::string getName() const { return name; }

    double getPrice() const { return price; }

    int getQuantity() const { return quantity; }

    double getDiscount() const { return discount; }

private:
    // Static variable declaration
    size_t number;
    static size_t nextNumber;
    std::string name;
    double price;
    int quantity;
    double discount;
};

size_t DishInfo::nextNumber = 1;

DishInfo::DishInfo(
    std::string NAME,
    double PRICE,
    int QUANTITY,
    double DISCOUNT) : name(NAME), price(PRICE), quantity(QUANTITY), discount(DISCOUNT), number(nextNumber++)
{
}

#endif
