/*
 *order
 *
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "menu.hpp"
#include "order.hpp"

class Customer
{
public:
    Customer(std::string name) : customerName(name) {}
    void orderFood();

private:
    Order order;
    std::string customerName;
};

void Customer::orderFood()
{
    order.orderDish();
    order.outfileOrder();
    order.displayOrder();
}

#endif