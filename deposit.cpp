#include "Deposit.h"

Deposit::Deposit() :Transaction() {
}

Deposit::Deposit(int accountID, Date date, int amount) :Transaction(accountID, date, amount) {
}

TransactionType Deposit::GetType() const {
    return TransactionType::DEPOSIT;
}