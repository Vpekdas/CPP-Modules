#ifndef CONTACT_HPP
#define CONTACT_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include "iostream"
#include <cstddef>
#include <string>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// CLASS //	+	+	+	+ 	+	+	+		//
// -----------------------------------------------------------------------------//

class Contact {
  public:
    Contact();
    ~Contact();

    void setIndex(const std::size_t index);
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

  private:
    std::size_t index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif