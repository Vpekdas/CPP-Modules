#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>

struct Date {
    int year;
    int month;
    int day;
    std::string fullFormat;
};

class BitcoinExchange {
    public:
    // Default constructor
    BitcoinExchange();

    // Copy Constructor
    BitcoinExchange(const BitcoinExchange &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    BitcoinExchange &operator=(const BitcoinExchange &other);

    // Default Destructor
    ~BitcoinExchange();

    void parseDatabase(const std::string &path);
    void parseInput(const std::string &path);

    private:
    std::map<std::string, float> _database;
    void validateDate(Date &date);
    void validateValue(const std::string &value, Date &date);
};

#endif // BITCOIN_EXCHANGE_HPP
