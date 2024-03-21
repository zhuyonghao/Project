/*
 *stat and manage
 *login
 *CRUD
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>

class Administrator
{
public:
    Administrator(std::string USERNAME,
                  std::string PASSWORD) : userName(USERNAME), password(PASSWORD) {}
    bool login();

private:
    std::string userName;
    std::string password;
};

bool Administrator::login()
{
}

#endif