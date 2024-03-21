/*
 *dislpayOrder
 */

#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
public:
    void outfileOrder(std::string fileName);
    void displayOrder();

private:
    size_t number;
    std::string name;
    double price;
    int quantity;
    double discount;
    double totalPrice;
};

#endif