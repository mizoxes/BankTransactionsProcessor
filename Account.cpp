#include "Account.h"

Account::Account() {
    this->ID = -1;
    this->money = 0;
}

Account::Account(int ID, std::string username, std::string password, int money) {
    this->ID = ID;
    this->username = username;
    this->password = password;
    this->money = money;
}

void Account::SetID(int ID) {
    this->ID = ID;
}

void Account::SetUsername(std::string username) {
    this->username = username;
}

void Account::SetPassword(std::string password) {
    this->password = password;
}

void Account::SetMoney(int money) {
    this->money = money;
}

int Account::GetID() const {
    return ID;
}

std::string Account::GetUsername() const {
    return username;
}

std::string Account::GetPassword() const {
    return password;
}

int Account::GetMoney() const {
    return money;
}

void Account::Deposit(int amount) {
    money += amount;
}

void Account::Withdraw(int amount) {
    money -= amount;
}
