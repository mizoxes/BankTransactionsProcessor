#include "Transfer.h"

Transfer::Transfer() :Transaction() {
}

Transfer::Transfer(int accountID, Date date, int amount, int receiverID) :Transaction(accountID, date, amount), receiverID(receiverID) {
}

TransactionType Transfer::GetType() const {
    return TransactionType::TRANSFER;
}

void Transfer::SetReceiverID(int id) {
    receiverID = id;
}

int Transfer::GetReceiverID() const {
    return receiverID;
}

std::string Transfer::ToString() const {
    return Transaction::ToString() + " " + std::to_string(receiverID);
}