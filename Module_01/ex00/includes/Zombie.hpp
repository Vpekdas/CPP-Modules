#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// COLORS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLACK "\033[0;30m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"
#define PINK "\033[0;95m"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// BOLD COLORS //	+	+	+	+ 	+	+	//
// -----------------------------------------------------------------------------//

#define BYELLOW "\033[1;33m"
#define BGREEN "\033[1;32m"
#define BBLUE "\033[1;34m"
#define BRED "\033[1;31m"
#define BPURPLE "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BBLACK "\033[1;30m"
#define BWHITE "\033[1;37m"
#define BPINK "\033[1;95m"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// NEON COLORS //	+	+	+	+ 	+	+	//
// -----------------------------------------------------------------------------//

#define NYELLOW "\033[1;93m"
#define NGREEN "\033[1;92m"
#define NBLUE "\033[1;94m"
#define NRED "\033[1;91m"
#define NPURPLE "\033[1;95m"
#define NCYAN "\033[1;96m"
#define NBLACK "\033[1;90m"
#define NWHITE "\033[1;97m"
#define NPINK "\033[1;95m"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>
#include <string>

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