#ifndef TRANSFER_H
#define TRANSFER_H

#include "Transaction.h"

class Transfer : public Transaction {
public:
    Transfer();
    Transfer(int accountID, Date date, int amount, int receiverID);

    TransactionType GetType() const;

    void SetReceiverID(int receiverID);
    int GetReceiverID() const;

    std::string ToString() const;

private:
    int receiverID;
};

#endif