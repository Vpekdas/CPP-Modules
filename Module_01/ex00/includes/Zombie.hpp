#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class Zombie {
  public:
    void announce(void);

    // Getter for the Zombie's name.
    std::string getName() const;

    // Setter for the Zombie's name.
    void setName(std::string name);

    // COnstructor
    Zombie();

    // Deconstructor
    ~Zombie();

  private:
    std::string name;
};

// Dynamically allocate and return a pointer to a new Zombie object using the 'new' keyword.
Zombie *newZombie(std::string name);

// Instantiate a Zombie object on the stack and initialize it with the given name.
void randomChump(std::string name);

#endif