/*
 *dislpayOrder
 */

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include "menu.hpp"
#include "orderInfo.hpp"

class Order
{
public:
    Order() { menu = Menu::getMenu(); }

    void outfileOrder(std::string fileName);

    void orderDish();

    void displayOrder() const;

private:
    Menu *menu;
    std::vector<OrderInfo> order;
};

void Order::orderDish()
{
    size_t number;

    menu->displayMenu();

    while (true)
    {
        std::cout << "Please Enter the serial number to order your meal(0 to quit): ";
        std::cin >> number;
        if (number == 0)
            break;

        for (auto it = menu->getDishInfo().begin(); it != menu->getDishInfo().end(); it++)
            if (it->getNumber() == number)
            {
                it->setQuantity() = it->getQuantity() - 1;
                OrderInfo orderInfo(it->getNumber(), it->getName(),
                                    it->getPrice(), 1, it->getDiscount());
                order.push_back(orderInfo);
            }
        std::cout << '\n';
    }

    std::cout << "Ordered successfully!\n";
}

void Order::displayOrder() const
{
    double totalPrice = 0;

    std::cout << "\nYour order information:\n";

    std::cout << "number" << '\t'
              << "name" << '\t'
              << "price" << '\t'
              << "quantity" << '\t'
              << "discount" << '\t'
              << "total price" << '\n';

    for (const OrderInfo &orderInfo : order)
    {
        std::cout
            << orderInfo.getNumber() << '\t'
            << orderInfo.getName() << '\t'
            << orderInfo.getPrice() << '\t'
            << orderInfo.getQuantity() << "\t\t"
            << orderInfo.getDiscount() << "\t\t"
            << orderInfo.getTotalPrice() << '\n';
        totalPrice += orderInfo.getTotalPrice();
    }
    std::cout << "\t\t\t\t\t\t\t" << totalPrice << "\n";
    std::cout << "\n\n";
}

#endif