#include <ostream>

#include "b.hpp"

B::B() : _b(0), _a(nullptr), _c(nullptr) { }

B::B(int n) : _b(n), _a(nullptr), _c(nullptr) { }

void B::set_a(A *a) {
    _a = a;
}

void B::set_c(C *c) {
    _c = c;
}

std::ostream& operator<<(std::ostream& os, B const& b) {
    return os << "Clase B, b = " << b._b;
}
