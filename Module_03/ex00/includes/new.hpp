#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //      +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

class CLASSNAME {
  public:
    // Default Constructor
    CLASSNAME();

    // Destructor
    ~CLASSNAME();

    // Copy Constructor
    CLASSNAME(const CLASSNAME &other);

    // Copy Assignment Operator
    CLASSNAME &operator=(const CLASSNAME &other);

  private:
};

#endif // CLASSNAME_HPP