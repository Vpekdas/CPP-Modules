#ifndef WEAPON_H

#define WEAPON_H

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
//	+	+	+	+	+	+	+	//  LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class Weapon {
  private:
    std::string type;

  public:
    // Constructor that initializes the weapon with a given type name.
    Weapon(const std::string &type);
    // Deconstructor
    ~Weapon();

    // Returns a const reference to avoid copying the string.
    const std::string &getType();

    // Setter for the weapon's type.
    void setType(std::string type);
};

#endif