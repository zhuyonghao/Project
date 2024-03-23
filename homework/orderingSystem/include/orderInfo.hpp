#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <iostream>

class OrderInfo
{
public:
    // getValue
    OrderInfo(size_t number,
              std::string name,
              double price,
              int quantity,
              double discount)
    {
        this->number = number;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->discount = discount;
    }

    size_t getNumber() const { return number; }

    std::string getName() const { return name; }

    double getPrice() const { return price; }

    int getQuantity() const { return quantity; }

    double getDiscount() const { return discount; }

    double getTotalPrice() const { return quantity * discount * price; }

private:
    size_t number;
    std::string name;
    double price;
    int quantity;
    double discount;
};

#endif