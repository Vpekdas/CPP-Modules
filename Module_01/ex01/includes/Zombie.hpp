#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <cstdlib>
#include <iostream>
#include <string>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// CLASS //	+	+	+	+ 	+	+	+	+	//
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

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// FUNCTIONS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

// Dynamically allocate an array of N Zombie objects, set their names to 'name', and return a
// pointer to the first Zombie.
Zombie *zombieHorde(int N, std::string name);

#endif