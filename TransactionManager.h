#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <vector>
#include "Transaction.h"

class TransactionManager {
public:
    bool SaveTransaction(const Transaction& transaction);
    std::vector<Transaction*> GetAccountTransactionsByID(int accountID);
    void DestroyTransactions(const std::vector<Transaction *>& transactions);
};

#endif