//
// Created by 123 on 2019-11-27.
//

#ifndef BLOCKCHAINHASHING_USERLIST_H
#define BLOCKCHAINHASHING_USERLIST_H


#include <cstdint>
#include <vector>
#include <stdexcept>
#include "Block.h"

class Users
{
public:
    Users();

    void AddUser(int newid, std::string username, std::string usersurname, double startSum);
    bool tranaction(double amount, Users &toUser);
    bool addMoney(double amount);
    std::string userNameAndSurname();
    double currentMoney();

private:
    int id;
    std::string name;
    std::string surname;
    double money;
};

void Users::AddUser(int newid, std::string username, std::string usersurname, double startSum) {
    id = newid;
    name = username;
    surname = usersurname;
    money = startSum;
}

bool Users::tranaction(double amount, Users &toUser) {
    if (money >= amount)
    {
        money -= amount;
        toUser.addMoney(amount);
        return true;
    }
    return false;
}

double Users::currentMoney() {
    return money;
}

bool Users::addMoney(double amount) {
    money += amount;
}


std::string Users::userNameAndSurname() {
    return name + " " + surname;
}

Users::Users() {
    id = 0;
    name = "";
    surname = "";
    money = 0;
}

#endif //BLOCKCHAINHASHING_USERLIST_H
