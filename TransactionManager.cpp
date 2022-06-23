#include "TransactionManager.h"
#include <fstream>

#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer.h"

using namespace std;

bool TransactionManager::SaveTransaction(const Transaction& transaction) {
    ofstream ofs("Transactions.txt", ios::app);
    if (!ofs)
        return false;
    ofs << transaction.ToString() << endl;
    return true;
}
vector<Transaction*> TransactionManager::GetAccountTransactionsByID(int accountID) {
    vector<Transaction *> transactions;

    ifstream ifs("Transactions.txt");
    if (ifs) {
        string _type;
        int _accountID;
        string _date;
        int _amount;
        int _receiverID;

        while (ifs >> _type >> _accountID >> _date >> _amount) {
            if (_type == "TRANSFER") {
                ifs >> _receiverID;
            }

            if (accountID == _accountID) {
                Date d;
                d.FromString(_date);
                if (_type == "DEPOSIT") {
                    transactions.push_back(new Deposit(_accountID, d, _amount));
                }
                else if (_type == "WITHDRAW") {
                    transactions.push_back(new Withdraw(_accountID, d, _amount));
                }
                else {
                    transactions.push_back(new Transfer(_accountID, d, _amount, _receiverID));
                }
            }
        }
    }

    return transactions;
}

void TransactionManager::DestroyTransactions(const std::vector<Transaction *>& transactions) {
    for (auto transaction : transactions) {
        delete transaction;
    }
}