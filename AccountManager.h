#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <string>
#include "Account.h"

class AccountManager {
public:
    bool LoadAccount(const std::string &username, const std::string &password, Account& account);
    bool SaveAccount(const Account& account);
    bool GetAccountByID(int ID, Account& account);
};

#endif