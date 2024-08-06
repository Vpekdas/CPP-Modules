#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// HEADERS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include "../includes/Contact.hpp"
#include <cstdlib>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// CLASS //	+	+	+	+ 	+	+	+		//
// -----------------------------------------------------------------------------//

class PhoneBook {
  public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const Contact &contact);
    void displayContacts();
    void displaySpecificContact(std::size_t index);

  private:
    Contact contacts[8];
    std::size_t totalContacts;
    std::size_t nextIndex;
};

#endif