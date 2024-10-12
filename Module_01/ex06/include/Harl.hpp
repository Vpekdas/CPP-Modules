#ifndef HARL_HPP

#define HARL_HPP

#include <iostream>

enum ComplaintLevel {
    DEBUG = 1,
    INFO,
    WARNING,
    ERROR
};

class Harl {
    public:
    Harl();
    ~Harl();
    void complain(std::string level);

    private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);

    // Struct to map complaint levels to their corresponding member function pointers.
    // This allows dynamic selection and invocation of the appropriate complaint handling method
    // based on the level.
    struct Complaints {
        std::string level;
        void (Harl::*complain)();
    };

    Complaints complaints[4];
};

#endif