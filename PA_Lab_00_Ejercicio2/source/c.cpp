#include <ostream>

#include "c.hpp"

C::C() : _c(0), _a(nullptr), _b(nullptr) { }

C::C(int n) : _c(n), _a(nullptr), _b(nullptr) { }

void C::set_a(A *a) {
    _a = a;
}

void C::set_b(B *b) {
    _b = b;
}

std::ostream& operator<<(std::ostream& os, C const& c) {
    return os << "Clase C, c = " << c._c;
}