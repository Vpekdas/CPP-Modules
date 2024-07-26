#ifndef CONTACT_H
#define CONTACT_H

#include <cstddef>
#include <iterator>
#include <string>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLACK "\033[0;30"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#define BYELLOW "\033[1;33m"
#define BGREEN "\033[1;32m"
#define BBLUE "\033[1;34m"
#define BRED "\033[1;31m"
#define BPURPLE "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BBLACK "\033[1;30m"
#define BWHITE "\033[1;37m"

class Contact {
  private:
    std::size_t index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

  public:
    Contact();
    Contact(const Contact &other);
    ~Contact();

    void setIndex(const std::size_t &index);
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    std::size_t getIndex() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif