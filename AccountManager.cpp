#include "AccountManager.h"
#include <fstream>

using namespace std;

bool AccountManager::LoadAccount(const std::string &username, const std::string &password, Account& account) {
    ifstream ifs("Accounts.txt");
    if (!ifs)
        return false;

    int _ID;
    string _username;
    string _password;
    int _money;

    while (ifs >> _ID >> _username >> _password >> _money) {
        if (username == _username && password == _password) {
            account.SetID(_ID);
            account.SetUsername(_username);
            account.SetPassword(_password);
            account.SetMoney(_money);
            return true;
        }
    }
    return false;
}

bool AccountManager::SaveAccount(const Account& account) {
    ofstream ofs("tmp.txt");
    if (!ofs)
        return false;

    int _ID;
    string _username;
    string _password;
    int _money;

    ifstream ifs("Accounts.txt");
    if (ifs) {
        while (ifs >> _ID >> _username >> _password >> _money) {
            if (account.GetUsername() != _username) {
                ofs << _ID << " " << _username << " " << _password << " " << _money << endl;
            }
        }
        ifs.close();
        remove("Accounts.txt");
    }
    
    ofs << account.GetID() << " " << account.GetUsername() << " " << account.GetPassword() << " " << account.GetMoney() << endl;
    
    ofs.close();
    rename("tmp.txt", "Accounts.txt");

    return true;
}

bool AccountManager::GetAccountByID(int ID, Account& account) {
    ifstream ifs("Accounts.txt");
    if (!ifs)
        return false;

    int _ID;
    string _username;
    string _password;
    int _money;

    while (ifs >> _ID >> _username >> _password >> _money) {
        if (_ID == ID) {
            account.SetID(_ID);
            account.SetUsername(_username);
            account.SetPassword(_password);
            account.SetMoney(_money);
            return true;
        }
    }
    return false;
}