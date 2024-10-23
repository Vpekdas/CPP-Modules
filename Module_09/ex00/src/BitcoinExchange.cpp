#include "../include/BitcoinExchange.hpp"
#include "../include/colors.hpp"

static int daysInMonth(int month, int year);
static std::size_t countSpace(const std::string &value);
static bool countSeparatorInDate(const std::string &date);
static std::size_t findStartIndex(const std::string &value);
static bool validFormat(const std::string &value);

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

        std::size_t comaIndex = line.find(",");

        if (comaIndex == std::string::npos) {
            std::stringstream ss;
            ss << "Error: input.csv is not formatted correctly (" << line << ").";
            throw std::runtime_error(ss.str());
        }

        // Since the CSV file is provided as per the subject requirements, we assume that the database
        // will always be correctly formatted.
        date = line.substr(0, comaIndex);

        exchangeRate = line.substr(comaIndex + 1);

        // Use std::stof instead of std::atof because std::stof throws an exception on error,
        // allowing us to handle invalid input more gracefully.
        _database[date] = std::stof(exchangeRate.c_str());
    }
}

bool BitcoinExchange::validateDate(Date &dates) {
    std::stringstream ss;

    if (!countSeparatorInDate(dates.fullFormat)) {
        std::cerr << NEON_RED
                  << "❌ Error: Invalid date format. Expected format is YYYY-MM-DD. Found: " << dates.fullFormat
                  << RESET << std::endl;
        return false;
    }

    if (dates.year <= 0) {
        std::cerr << NEON_RED << "❌ Error: Invalid year. Year must be greater than 0. Found: " << dates.year
                  << " in date: " << dates.fullFormat << RESET << std::endl;
        return false;
    }

    if (dates.month <= 0 || dates.month > 12) {
        std::cerr << NEON_RED << "❌ Error: Invalid month. Month must be between 1 and 12. Found: " << dates.month
                  << " in date: " << dates.fullFormat << RESET << std::endl;
        return false;
    }

    int maxDay = daysInMonth(dates.month, dates.year);

    if (dates.day < 0 || dates.day > maxDay) {
        std::cerr << NEON_RED << "❌ Error: Invalid day. Day must be between 1 and " << maxDay
                  << ". Found: " << dates.day << " in date: " << dates.fullFormat << "." << RESET << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::findLowerDate(Date &date, float result) {
    std::map<std::string, float>::iterator it;

    for (int y = date.year; y > 0; y--) {

        // If we are in the same year as the starting date, use the starting month.
        // Otherwise, start from December and decrement.
        for (int m = (y == date.year ? date.month : 12); m > 0; m--) {

            // If we are in the same month and year as the starting date, use the starting day.
            // Otherwise, start from the last day of the month and decrement.
            for (int d = (y == date.year && m == date.month ? date.day : daysInMonth(m, y)); d > 0; d--) {

                // Format the current date components (year, month, day) into a string in the format YYYY-MM-DD.
                // This formatted string is used to search for the date in our <map> database.
                std::stringstream newDate;
                newDate << y << "-" << std::setw(2) << std::setfill('0') << m << "-" << std::setw(2) << d;

                it = _database.find(newDate.str());

                if (it != _database.end()) {
                    std::stringstream ss;

                    ss << std::fixed << std::setprecision(2) << it->second * result;

                    std::cout << NEON_CYAN << "Date: " << date.fullFormat << " => Result: " << ss.str() << RESET
                              << std::endl;
                    return;
                }
            }
        }
    }
    std::cerr << NEON_RED << "❌ Error: No value found for the specified date or any earlier date in the database."
              << RESET << std::endl;
}

bool BitcoinExchange::validateFloat(const std::string &value, Date &date) {
    std::stringstream ss;
    std::stringstream ssWithoutZero;
    std::string valueWithoutZero;

    std::size_t indexNumber = findStartIndex(value);

    float result = std::atof(value.c_str());

    // Since itoa does not exist in standard C++, we use a stringstream to convert the number to a string.
    // Later, we will use the str() method to compare the converted number with the original string.
    ss << result;

    // Skip leading zeros to accurately compare the floating-point conversion (std::atof) with the original string.
    // This allows us to check if the input was altered due to reasons like overflow or other anomalies.
    valueWithoutZero = value.substr(indexNumber);

    if (value.find("-") != std::string::npos) {
        ssWithoutZero << "-" << valueWithoutZero.c_str();
    } else {
        ssWithoutZero << valueWithoutZero.c_str();
    }

    // \n instead of std::endl because code was too slow.
    if ((!validFormat(ssWithoutZero.str())) || (ssWithoutZero.str() != ss.str())) {
        std::cerr << NEON_RED
                  << "❌ Error: Invalid value format. Expected a valid floating-point number. Found: " << value
                  << " (Processed: " << ssWithoutZero.str() << ")." << RESET << "\n";
        return false;
    }

    if (result < 0 || result > 1000) {
        std::cerr << NEON_RED << "❌ Error: Value out of range. The value must be between 0 and 1000. Found: " << result
                  << " (Processed: " << ss.str() << ")." << RESET << "\n";
        return false;
    } else {

        std::map<std::string, float>::iterator it = _database.find(date.fullFormat);

        // If the exact date is not found in the database, find the closest earlier date.
        if (it == _database.end()) {
            findLowerDate(date, result);
            return false;
        }

        // Format the result with fixed-point notation and two decimal places, then display it.
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << it->second * result;

        std::cout << NEON_CYAN << "Date: " << date.fullFormat << " => Result: " << ss.str() << RESET << std::endl;
    }
    return true;
}

bool BitcoinExchange::validateInt(const std::string &value, Date &date) {
    std::stringstream ss;
    std::stringstream ssWithoutZero;
    std::string valueWithoutZero;

    std::size_t indexNumber = findStartIndex(value);

    int result = std::atoi(value.c_str());

    // Since itoa does not exist in standard C++, we use a stringstream to convert the number to a string.
    // Later, we will use the str() method to compare the converted number with the original string.
    ss << result;

    // Skip leading zeros to accurately compare the floating-point conversion (std::atof) with the original string.
    // This allows us to check if the input was altered due to reasons like overflow or other anomalies.
    valueWithoutZero = value.substr(indexNumber);

    if (value.find("-") != std::string::npos) {
        ssWithoutZero << "-" << valueWithoutZero.c_str();
    } else {
        ssWithoutZero << valueWithoutZero.c_str();
    }

    // \n instead of std::endl because code was too slow.
    if ((!validFormat(ssWithoutZero.str())) || (ssWithoutZero.str() != ss.str())) {
        std::cerr << NEON_RED << "❌ Error: Invalid value format. Expected a valid integer number. Found: " << value
                  << " (Processed: " << ssWithoutZero.str() << ")." << RESET << "\n";
        return false;
    }

    if (result > 1000 || result < 0) {
        std::cerr << NEON_RED << "❌ Error: Value out of range. The value must be between 0 and 1000. Found: " << result
                  << " (Processed: " << ss.str() << ")." << RESET << "\n";
        return false;
    } else {

        std::map<std::string, float>::iterator it = _database.find(date.fullFormat);
        // If the exact date is not found in the database, find the closest earlier date.
        if (it == _database.end()) {
            findLowerDate(date, result);
            return false;
        }

        // Format the result then display it.
        std::stringstream ss;
        ss << it->second * result;
        std::cout << NEON_CYAN << "Date: " << date.fullFormat << " => Result: " << ss.str() << RESET << std::endl;
    }
    return true;
}

// Call either std::atoi or std::atof based on the type of the variable.
// This is necessary because each type (integer or float) has its own overflow behavior.
// Using the appropriate function (std::atoi for integers and std::atof for floats) allows us to detect overflow
// conditions specific to each type.
bool BitcoinExchange::validateValue(const std::string &value, Date &date) {
    if (value.find('.') != std::string::npos) {
        return validateFloat(value, date);
    } else {
        return validateInt(value, date);
    }
}

void BitcoinExchange::parseInput(const std::string &path) {
    std::ifstream file;

    std::string line;
    std::string date;
    std::string value;

    std::size_t firstSeparatorIndex;
    std::size_t lastSeparatorIndex;

    file.open(path.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("❌ Error: Unable to open file. Please check the file path and permissions. Path: " +
                                 path);
    }
    // Skip the header line
    while (std::getline(file, line)) {
        if (line == "date | value") {
            continue;
        }

        std::size_t pipeSeparatorIndex = line.find("|");
        if (pipeSeparatorIndex == std::string::npos) {
            std::cerr << NEON_RED << "❌ Error: Invalid format. Expected format is 'date | value'. Found: \"" << line
                      << "\". Please ensure the line is correctly formatted." << RESET << std::endl;
            continue;
        }

        // Extract the date part from the line using the position of the pipe separator.
        // This allows us to parse and store the year, month, and day as integers in a structured format.
        date = line.substr(0, pipeSeparatorIndex - 1);

        Date dates;

        dates.fullFormat = date;

        firstSeparatorIndex = date.find("-");
        lastSeparatorIndex = date.rfind("-");

        if (firstSeparatorIndex == std::string::npos || lastSeparatorIndex == std::string::npos) {
            std::cerr << NEON_RED << "❌ Error: wrong date format. date should be on format YYYY-NN-DD" << RESET
                      << std::endl;
            continue;
        }

        dates.year = std::atoi(date.substr(0, firstSeparatorIndex).c_str());

        dates.month =
            std::atoi(date.substr(firstSeparatorIndex + 1, lastSeparatorIndex - firstSeparatorIndex - 1).c_str());

        dates.day = std::atoi(date.substr(lastSeparatorIndex + 1).c_str());

        if (!validateDate(dates)) {
            continue;
        }

        pipeSeparatorIndex = line.find("|");
        if (pipeSeparatorIndex == std::string::npos) {
            std::cerr << NEON_RED << "Error: Wrong format. Format should be date | value." << RESET << std::endl;
            continue;
        }

        // Detect where the value starts and then skip leading spaces.
        // This allows us to handle cases where there are multiple spaces before the number after the pipe separator.
        value = line.substr(pipeSeparatorIndex + 1);

        value = value.substr(countSpace(value));

        validateValue(value, dates);
    }
}

static int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year and adjust February days.
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return 29;
    }

    return days[month - 1];
}

static std::size_t countSpace(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (value[i] != ' ') {
            return i;
        }
    }
    return 0;
}

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

// Skip leading zeros as they are ignored by std::atof and std::atoi.
// This ensures consistency when comparing the original string with the converted value, helping to detect anomalies.
static std::size_t findStartIndex(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (std::isdigit(value[i]) && value[i] != '0') {
            return i;
        }
    }
    return 0;
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