#include "../includes/Account.hpp"
#include "iostream"
#include <ctime>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[42];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::strftime(buffer, 42, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created"
              << std::endl;
}

Account::~Account() {
    _displayTimestamp();
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
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit
              << ";deposit:" << deposit << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (this->_amount < withdrawal) {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals += 1;
    this->_amount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal
              << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
