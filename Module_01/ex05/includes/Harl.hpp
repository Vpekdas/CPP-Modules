#ifndef HARL_HPP

#define HARL_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// COLORS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include <string>
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLACK "\033[0;30m"
#define WHITE "\033[0;37m"
#define PINK "\033[0;95m"
#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"

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
#define BORANGE "\033[1;38;5;214m"

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
#define NORANGE "\033[1;38;5;208m"

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

    struct Complaints {
        std::string level;
        void (Harl::*complain)();
    };

    Complaints complaints[4];
};

#endif