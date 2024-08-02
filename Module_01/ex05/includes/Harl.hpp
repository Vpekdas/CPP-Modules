#ifndef HARL_HPP

#define HARL_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class Harl {
  public:
    // Constructor: Initializes the Harl object
    Harl();
    // Destructor: Cleans up any resources used by the Harl object
    ~Harl();
    // Function that will detect which complaint should be called
    void complain(std::string level);

  private:
    //   Handles the DEBUG level complaint.
    void debug(void);
    // Handles the INFO level complaint.
    void info(void);
    // Handles the WARNING level complaint.
    void warning(void);
    // Handles the ERROR level complaint.
    void error(void);

    // Struct to store the level name and a pointer to the corresponding function.
    struct Complaints {
        std::string level;
        void (Harl::*complain)();
    };

    // Array to store 4 complaints.
    Complaints complaints[4];
};

#endif