#pragma once

#include <iosfwd>

#include "b.hpp"
#include "c.hpp"

class A {
    int _a;
    B* _b;
    C* _c;

public:
    A();
    A(int n);

    void set_b(B *b);
    void set_c(C *c);

    friend std::ostream& operator<<(std::ostream&, A const& a);
};
