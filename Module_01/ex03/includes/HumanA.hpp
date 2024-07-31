#ifndef HUMAN_A_HPP

#define HUMAN_A_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include "../includes/Weapon.hpp"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class HumanA {
  private:
    Weapon &weapon;
    std::string name;

  public:
    //   Constructor
    HumanA(const std::string &name, Weapon &weapon);
    //   Deconstructor
    ~HumanA();

    // Returns a const string to ensure the state of the object is not modified.
    const std::string getName() const;

    // Display an attack message that shows the name and the weapon type.
    void attack();
};

#endif