#include "Withdraw.h"

Withdraw::Withdraw() :Transaction() {
}

Withdraw::Withdraw(int accountID, Date date, int amount) :Transaction(accountID, date, amount) {
}

TransactionType Withdraw::GetType() const {
    return TransactionType::WITHDRAW;
}