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
    Customer(std::string name) : customerName(name), menu(), order() {}
    void orderFood();

private:
    Menu menu;
    Order order;
    std::string customerName;
};

void Customer::orderFood()
{
    menu.displayMenu();
    order.outfileOrder(customerName);
    order.displayOrder();
}

#endif