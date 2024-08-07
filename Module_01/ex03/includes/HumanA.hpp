#ifndef HUMAN_A_HPP

#define HUMAN_A_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  HEADERS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

#include "../includes/Weapon.hpp"

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	//  CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class HumanA {
  public:
    // Constructor that initializes HumanA with a name and a reference to a Weapon.
    // Using a reference ensures that HumanA always has a valid weapon and reflects any changes to
    // the weapon.
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();

    const std::string getName() const;

    void attack();

  private:
    Weapon &weapon;
    std::string name;
};

#endif