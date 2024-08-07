#ifndef HUMAN_B_HPP

#define HUMAN_B_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  HEADERS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

#include "../includes/Weapon.hpp"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class HumanB {
  public:
    //   Constructor
    HumanB(const std::string &name);
    //   Deconstructor
    ~HumanB();

    // Setter for the human's weapon.
    void setWeapon(Weapon &weapon);

    // Returns a const string to ensure the state of the object is not modified.
    const std::string getName() const;

    // Display an attack message that shows the name and the weapon type.
    void attack();

  private:
    Weapon *weapon;
    std::string name;
};

#endif