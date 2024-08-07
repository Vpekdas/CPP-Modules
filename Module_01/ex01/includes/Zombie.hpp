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
    Zombie();
    ~Zombie();

    std::string getName() const;
    void setName(std::string name);

    void announce(void);

  private:
    std::string name;
};

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// FUNCTIONS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

// Creates an array of Zombies on the heap, each with the given name.
// This is useful for creating a group of Zombies that can be managed together.
Zombie *zombieHorde(int N, std::string name);

#endif