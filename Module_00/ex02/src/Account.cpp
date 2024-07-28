#include "../includes/Account.hpp"
#include "iostream"
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created"
              << std::endl;
}

Account::~Account() {
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed"
              << std::endl;
}

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount() {
    return Account::_totalAmount;
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (this->_amount < withdrawal) {
        std::cout << "withdrawal:refused";
        return false;
    }
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    return true;
}

void Account::displayStatus(void) const {
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
