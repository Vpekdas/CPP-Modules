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
    // Adds a new contact to the PhoneBook.
    void addContact(const Contact &contact);
    // Displays all contacts with general information.
    void displayContacts();
    // Allows the user to choose an index to display all information.
    void displaySpecificContact(std::size_t index);

  private:
    //   Only 8 contacts can be stored.

    Contact contacts[8];
    std::size_t totalContacts;
    // Allows incrementing and wrapping around to the oldest contact.
    std::size_t nextIndex;
};

#endif