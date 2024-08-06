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
    Zombie();
    ~Zombie();

    void announce(void);
    std::string getName() const;
    void setName(std::string name);

  private:
    std::string name;
};

// Creates a new Zombie object on the heap to allow for dynamic lifetime management.
// This is useful when the Zombie's lifetime needs to extend beyond the scope in which it was
// created.
Zombie *newZombie(std::string name);

// Creates a Zombie object on the stack and immediately announces its presence.
// This is useful for temporary Zombies that do not need to persist beyond the function scope.
void randomChump(std::string name);

#endif