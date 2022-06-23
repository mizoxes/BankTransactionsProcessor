#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"

enum class TransactionType {
    DEPOSIT,
    WITHDRAW,
    TRANSFER
};

class Transaction {
public:
    Transaction();
    Transaction(int accountID, Date date, int amount);

    virtual TransactionType GetType() const = 0;

    void SetAccountID(int accountID);
    void SetDate(Date date);
    void SetAmount(int amount);

    int GetAccountID() const;
    Date GetDate() const;
    int GetAmount() const;

    virtual std::string ToString() const;

    static std::string ToString(TransactionType type);

protected:
    int     accountID;
    Date    date;
    int     amount;
};

#endif