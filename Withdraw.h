#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "Transaction.h"

class Withdraw : public Transaction {
public:
    Withdraw();
    Withdraw(int accountID, Date date, int amount);

    TransactionType GetType() const;
};

#endif