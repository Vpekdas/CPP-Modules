#include "../include/BitcoinExchange.hpp"
#include "../include/colors.hpp"
#include <cctype>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() : _database() {
    std::cout << YELLOW << "🛠️ Default BitcoinExchange Constructor called 🛠️" << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << RED << "🧨 BitcoinExchange Destructor called 🧨" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {
    std::cout << YELLOW << "🖨️ BitcoinExchange Copy Constructor called 🖨️" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    // Check for self-assignment
    if (this != &other) {
        _database = other._database;
    }
    std::cout << YELLOW << "📞 BitcoinExchange Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void BitcoinExchange::parseDatabase(const std::string &path) {
    std::ifstream file;
    std::string line;
    std::string date;
    std::string exchangeRate;

    file.open(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    while (std::getline(file, line)) {
        if (line == "date,exchange_rate")
            continue;
        date = line.substr(0, line.find(","));
        exchangeRate = line.substr(line.find(",") + 1, line.length() - line.find(","));
        _database[date] = std::atof(exchangeRate.c_str());
    }
}

void BitcoinExchange::validateDate(Date &dates) {
    std::ostringstream oss;

    if (dates.year < 0) {
        std::cerr << NEON_RED << "Error: year cannot be negative (" << dates.fullFormat << ")." << RESET << std::endl;
        return;
    }

    if (dates.month < 0 || dates.month > 12) {
        std::cerr << NEON_RED << "Error: month cannot be negative or higher than 12 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return;
    }

    // Special case for February month.
    if (dates.month == 2 && (dates.day < 0 || dates.day > 28)) {
        std::cerr << NEON_RED << "Error: day cannot be negative or higher than 28 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return;

    } else if (dates.day < 0 || dates.day > 31) {
        std::cerr << NEON_RED << "Error: day cannot be negative or higher than 31 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return;
    }
}

static std::size_t findStartIndex(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (value[i] == '-' || value[i] == '+' || std::isdigit(value[i])) {
            return i;
        }
    }
    return std::string::npos;
}

// TODO: Separate in 2 functions.
// TODO: Adapt set precision by counting ".".

void BitcoinExchange::validateValue(const std::string &value, Date &date) {
    std::stringstream oss;
    std::size_t indexNumber = findStartIndex(value);

    if (value.find(".") != std::string::npos) {
        float result = std::atof(value.c_str());

        oss << result;

        if (value.substr(indexNumber) != oss.str()) {
            std::cerr << NEON_RED << "Error: Value is not in Float range (" << oss.str() << ")." << RESET << std::endl;
            return;
        }

        if (result < 0 || result > 1000) {
            std::cerr << NEON_RED << "Error: Value cannot exceed 1000 or be less than 0 (" << oss.str() << ")." << RESET
                      << std::endl;
            return;
        } else {
            std::map<std::string, float>::iterator it = _database.find(date.fullFormat);
            if (it == _database.end()) {
                return;
            }
            std::stringstream oss;
            oss << std::fixed << std::setprecision(2) << it->second * result;
            std::cout << NEON_CYAN << date.fullFormat << " => " << oss.str() << RESET << std::endl;
        }
    } else {
        int result = std::atoi(value.c_str());

        oss << result;
        if (value.substr(indexNumber) != oss.str()) {
            return;
            std::cerr << NEON_RED << "Error: Value is not in Int range (" << oss.str() << ")." << RESET << std::endl;
            return;
        }
        if (result > 1000 || result < 0) {
            std::cerr << NEON_RED << "Error: Value cannot exceed 1000 or be less than 0 (" << oss.str() << ")." << RESET
                      << std::endl;
            return;
        } else {
            std::map<std::string, float>::iterator it = _database.find(date.fullFormat);
            if (it == _database.end()) {
                return;
            }

            std::stringstream oss;
            oss << std::fixed << std::setprecision(2) << it->second * result;
            std::cout << NEON_CYAN << date.fullFormat << " => " << oss.str() << RESET << std::endl;
        }
    }
}

void BitcoinExchange::parseInput(const std::string &path) {
    std::ifstream file;
    std::string line;

    std::string date;

    std::string value;

    std::size_t firstSeparatorIndex;
    std::size_t lastSeparatorIndex;
    std::size_t pipeIndex;

    file.open(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    while (std::getline(file, line)) {
        if (line == "date | value") {
            continue;
        }
        date = line.substr(0, line.find("|") - 1);

        Date dates;

        // TODO:  Be sure that dates contain only 3 "-" and only digit.

        dates.fullFormat = date;

        firstSeparatorIndex = date.find("-");
        lastSeparatorIndex = date.rfind("-");

        if (firstSeparatorIndex == std::string::npos || lastSeparatorIndex == std::string::npos) {
            std::cerr << NEON_RED << "Error: wrong date format. date should be on format YYYY-NN-DD" << RESET
                      << std::endl;
        }

        dates.year = std::stoi(date.substr(0, firstSeparatorIndex).c_str());

        dates.month =
            std::stoi(date.substr(firstSeparatorIndex + 1, lastSeparatorIndex - firstSeparatorIndex - 1).c_str());

        dates.day = std::stoi(date.substr(lastSeparatorIndex + 1).c_str());

        validateDate(dates);

        pipeIndex = line.find("|");
        if (pipeIndex == std::string::npos) {
            std::cerr << NEON_RED << "Error: Wrong format. Format should be date | value." << RESET << std::endl;
        }

        value = line.substr(pipeIndex + 1);
        validateValue(value, dates);
    }
}