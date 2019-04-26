#include <ostream>

#include "a.hpp"

A::A() : _a(0), _b(nullptr), _c(nullptr) { }

A::A(int n) : _a(n), _b(nullptr), _c(nullptr) { }

void A::set_b(B *b) {
    _b = b;
}

void A::set_c(C *c) {
    _c = c;
}

std::ostream& operator<<(std::ostream& os, A const& a) {
    return os << "Clase A, a = " << a._a;
}