#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"

class Deposit : public Transaction {
public:
    Deposit();
    Deposit(int accountID, Date date, int amount);

    TransactionType GetType() const;
};

#endif