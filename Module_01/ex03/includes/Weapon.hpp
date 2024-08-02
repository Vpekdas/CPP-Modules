#ifndef WEAPON_H

#define WEAPON_H

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class Weapon {
  public:
    // Constructor that initializes the weapon with a given type name.
    Weapon(const std::string &type);
    // Deconstructor
    ~Weapon();

    // Returns a const reference to avoid copying the string.
    const std::string &getType();

    // Setter for the weapon's type.
    void setType(std::string type);

  private:
    std::string type;
};

#endif