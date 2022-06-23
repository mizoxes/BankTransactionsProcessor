#include "Transaction.h"

Transaction::Transaction() {
    accountID = 0;
    date.day = date.month = date.year = 0;
    amount = 0;
}

Transaction::Transaction(int accountID, Date date, int amount) {
    this->accountID = accountID;
    this->date = date;
    this->amount = amount;
}

void Transaction::SetAccountID(int accountID) {
    this->accountID = accountID;
}

void Transaction::SetDate(Date date) {
    this->date = date;
}

void Transaction::SetAmount(int amount) {
    this->amount = amount;
}

int Transaction::GetAccountID() const {
    return accountID;
}

Date Transaction::GetDate() const {
    return date;
}

int Transaction::GetAmount() const {
    return amount;
}

std::string Transaction::ToString(TransactionType type) {
    switch (type) {
    case TransactionType::DEPOSIT:
        return "DEPOSIT";
    case TransactionType::WITHDRAW:
        return "WITHDRAW";
    default:
        return "TRANSFER";
    }
}

std::string Transaction::ToString() const {
    return Transaction::ToString(this->GetType()) + " " +
           std::to_string(accountID) + " " +
           date.ToString() + " " +
           std::to_string(amount);
}