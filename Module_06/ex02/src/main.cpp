#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"
#include "../include/colors.hpp"

Base *generate(void) {
    const int randNumber = (rand() % 3) + 1;
    switch (randNumber) {
    case 1:
        return new A();
    case 2:
        return new B();
    case 3:
        return new C();
    default:
        return new A();
    }
}

void identify(Base *p) {
    if (A *ap = dynamic_cast<A *>(p)) {
        std::cout << NEON_GREEN << "A" << RESET << std::endl;
        return;
    } else if (B *bp = dynamic_cast<B *>(p)) {
        std::cout << NEON_ORANGE << "B" << RESET << std::endl;
        return;
    } else if (C *cp = dynamic_cast<C *>(p)) {
        std::cout << NEON_PURPLE << "C" << RESET << std::endl;
        return;
    }
}

void identify(Base &p) {
    try {
        A &ap = dynamic_cast<A &>(p);
        (void)ap;
        std::cout << NEON_GREEN << "A" << RESET << std::endl;
        return;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        B &bp = dynamic_cast<B &>(p);
        (void)bp;
        std::cout << NEON_ORANGE << "B" << RESET << std::endl;
        return;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        C &cp = dynamic_cast<C &>(p);
        (void)cp;
        std::cout << NEON_PURPLE << "C" << RESET << std::endl;
        return;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }
}

int main() {
    srand((time(0)));

    Base *obj = generate();

    std::cout << BOLD_ITALIC_CYAN << "Using identify(Base *p): " << RESET << std::endl;
    identify(obj);

    std::cout << BOLD_ITALIC_CYAN << "Using identify(Base &p): " << RESET << std::endl;
    identify(*obj);

    delete obj;

    return 0;
}