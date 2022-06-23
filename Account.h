#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account();
    Account(int ID, std::string username, std::string password, int money);

    void SetID(int ID);
    void SetUsername(std::string username);
    void SetPassword(std::string password);
    void SetMoney(int money);

    int GetID() const;
    std::string GetUsername() const;
    std::string GetPassword() const;
    int GetMoney() const;

    void Deposit(int amount);
    void Withdraw(int amount);

private:
    int             ID;
    std::string     username;
    std::string     password;
    int             money;
};

#endif