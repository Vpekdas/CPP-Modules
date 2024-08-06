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
    // Constructor that initializes the Weapon with a specific type.
    // This ensures that every Weapon object starts with a valid type.
    Weapon(const std::string &type);
    ~Weapon();

    const std::string &getType();

    void setType(std::string type);

  private:
    std::string type;
};

#endif