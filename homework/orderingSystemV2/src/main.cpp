#include "administrator.hpp"
#include "customer.hpp"
#include "menu.hpp"
#include "order.hpp"
#include "userInterface.hpp"

int main()
{
    UserInterface ui("zyh", "123", "Z");
    ui.determineIdentity();
}