#include "../include/BitcoinExchange.hpp"
#include "../include/colors.hpp"

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

    file.open(path.c_str());

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

// TODO: Separate in multiple functions.
static bool countSeparatorInDate(const std::string &date) {
    std::size_t separatorCount = 0;
    for (std::size_t i = 0; i < date.length(); i++) {
        if (!std::isdigit(date[i]) && date[i] != '-') {
            return false;
        } else if (date[i] == '-') {
            separatorCount++;
        }
    }

    if (separatorCount != 2) {
        return false;
    }
    return true;
}

bool BitcoinExchange::validateDate(Date &dates) {
    std::ostringstream oss;

    if (!countSeparatorInDate(dates.fullFormat)) {
        std::cerr << NEON_RED << "Error: Wrong date format: (" << dates.fullFormat << ")." << RESET << std::endl;
        return false;
    }

    if (dates.year < 0) {
        std::cerr << NEON_RED << "Error: year cannot be negative (" << dates.fullFormat << ")." << RESET << std::endl;
        return false;
    }

    if (dates.month <= 0 || dates.month > 12) {
        std::cerr << NEON_RED << "Error: month cannot be negative or higher than 12 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return false;
    }

    // TODO:
    // https://stackoverflow.com/questions/37082316/return-number-of-days-in-a-given-month-of-a-given-year
    // tips for handling well 30 or 31 days.

    // Special case for February month.
    if (dates.month == 2 && (dates.day < 0 || dates.day > 28)) {
        std::cerr << NEON_RED << "Error: day cannot be negative or higher than 28 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return false;

    } else if ((dates.day < 0 || dates.day > 30) && (dates.month % 2 == 0)) {
        std::cerr << NEON_RED << "Error: day cannot be negative or higher than 30 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return false;
    } else if ((dates.day < 0 || dates.day > 31) && (dates.month % 2 != 0)) {
        std::cerr << NEON_RED << "Error: day cannot be negative or higher than 31 (" << dates.fullFormat << ")."
                  << RESET << std::endl;
        return false;
    }
    return true;
}

// TODO:
// https://stackoverflow.com/questions/37082316/return-number-of-days-in-a-given-month-of-a-given-year
// tips for handling well 30 or 31 days.
void BitcoinExchange::findLowerDate(Date &date, float result) {

    std::map<std::string, float>::iterator it;

    for (int i = 0; i < date.year; i++) {

        for (int i = 0; i < date.month; i++) {

            for (int i = 0; i < date.day; i++) {

                std::stringstream newDate;
                newDate << date.year << "-" << std::setw(2) << std::setfill('0') << date.month << "-" << std::setw(2)
                        << std::setfill('0') << date.day;

                it = _database.find(newDate.str());

                if (it != _database.end()) {
                    std::stringstream oss;
                    oss << std::fixed << std::setprecision(2) << it->second * result;
                    std::cout << NEON_CYAN << date.fullFormat << " => " << oss.str() << RESET << std::endl;
                    return;
                }
                date.day--;
            }
            date.month--;
            if (date.month % 2 == 0) {
                date.day = 30;
            } else {
                date.day = 31;
            }
        }
        date.month = 12;
        date.year--;
    }
}

// TODO: Separate in 2 functions.
// TODO: Adapt set precision by counting ".".

static std::size_t findStartIndex(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (std::isdigit(value[i]) && value[i] != '0') {
            return i;
        }
    }
    return std::string::npos;
}

static bool validFormat(const std::string &value) {
    std::size_t countOperator = 0;

    for (std::size_t i = 0; i < value.length(); i++) {
        if (!std::isdigit(value[i]) && value[i] != '-' && value[i] != '+' && value[i] != '.') {
            return false;
        } else if (value[i] == '-' || value[i] == '+') {
            if (i != 0) {
                return false;
            }
            countOperator++;
        }
    }

    if (countOperator > 1) {
        return false;
    }

    return true;
}

bool BitcoinExchange::validateValue(const std::string &value, Date &date) {
    std::stringstream oss;
    std::stringstream ossZero;
    std::string valueWithoutZero;

    std::size_t indexNumber = findStartIndex(value);

    if (value.find(".") != std::string::npos) {
        float result = std::atof(value.c_str());

        oss << result;

        valueWithoutZero = value.substr(indexNumber);

        if (value.find("-") != std::string::npos) {
            ossZero << "-" << valueWithoutZero.c_str();
        } else {
            ossZero << valueWithoutZero.c_str();
        }

        if ((!validFormat(ossZero.str())) || (ossZero.str() != oss.str())) {
            std::cerr << NEON_RED << "Error: Wrong value format (" << value << ")" << RESET << std::endl;
            return false;
        }

        if (result < 0 || result > 1000) {
            std::cerr << NEON_RED << "Error: Value cannot exceed 1000 or be less than 0 (" << oss.str() << ")." << RESET
                      << std::endl;
            return false;
        } else {
            std::map<std::string, float>::iterator it = _database.find(date.fullFormat);
            if (it == _database.end()) {
                findLowerDate(date, result);
                return false;
            }
            std::stringstream oss;
            oss << std::fixed << std::setprecision(2) << it->second * result;
            std::cout << NEON_CYAN << date.fullFormat << " => " << oss.str() << RESET << std::endl;
        }
    } else {
        int result = std::atoi(value.c_str());

        oss << result;

        valueWithoutZero = value.substr(indexNumber);

        if (value.find("-") != std::string::npos) {
            ossZero << "-" << valueWithoutZero.c_str();
        } else {
            ossZero << valueWithoutZero.c_str();
        }

        if ((!validFormat(ossZero.str())) || (ossZero.str() != oss.str())) {
            std::cerr << NEON_RED << "Error: Wrong value format. Verify that you are in Int range (" << value << ")"
                      << RESET << std::endl;
            return false;
        }

        if (result > 1000 || result < 0) {
            std::cerr << NEON_RED << "Error: Value cannot exceed 1000 or be less than 0 (" << oss.str() << ")." << RESET
                      << std::endl;
            return false;
        } else {
            std::map<std::string, float>::iterator it = _database.find(date.fullFormat);
            if (it == _database.end()) {
                findLowerDate(date, result);
                return false;
            }

            std::stringstream oss;
            oss << std::fixed << std::setprecision(2) << it->second * result;
            std::cout << NEON_CYAN << date.fullFormat << " => " << oss.str() << RESET << std::endl;
        }
    }
    return true;
}

static std::size_t countSpace(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (value[i] != ' ') {
            return i;
        }
    }
    return 0;
}

void BitcoinExchange::parseInput(const std::string &path) {
    std::ifstream file;
    std::string line;

    std::string date;

    std::string value;

    std::size_t firstSeparatorIndex;
    std::size_t lastSeparatorIndex;
    std::size_t pipeIndex;

    file.open(path.c_str());

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

        dates.year = std::atoi(date.substr(0, firstSeparatorIndex).c_str());

        dates.month =
            std::atoi(date.substr(firstSeparatorIndex + 1, lastSeparatorIndex - firstSeparatorIndex - 1).c_str());

        dates.day = std::atoi(date.substr(lastSeparatorIndex + 1).c_str());

        if (!validateDate(dates)) {
            continue;
        }

        pipeIndex = line.find("|");
        if (pipeIndex == std::string::npos) {
            std::cerr << NEON_RED << "Error: Wrong format. Format should be date | value." << RESET << std::endl;
            continue;
        }

        value = line.substr(pipeIndex + 1);

        value = value.substr(countSpace(value));

        validateValue(value, dates);
    }
}