/*
 *judge
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "administrator.hpp"
#include "customer.hpp"

class UserInterface
{
public:
    void determineIdentity();

private:
    Administrator administrator;
    Customer customer;
};

#endif