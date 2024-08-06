#ifndef HARL_HPP

#define HARL_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// LIBRARIES //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// ENUM //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

enum ComplaintLevel {
    DEBUG = 1,
    INFO,
    WARNING,
    ERROR
};

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// CLASS //	+	+	+	+ 	+	+	+	+	//
// -----------------------------------------------------------------------------//

class Harl {
  public:
    Harl();
    ~Harl();
    void complain(std::string level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    // Struct to map complaint levels to their corresponding methods.
    // This allows for dynamic method calling based on the complaint level.
    struct Complaints {
        std::string level;
        void (Harl::*complain)();
    };

    // Array to store the mapping of complaint levels to their corresponding methods.
    // This array is used to look up and call the appropriate method in complain().
    Complaints complaints[4];
};

#endif