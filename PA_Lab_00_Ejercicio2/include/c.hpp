#pragma once

#include <iosfwd>

#include "b.hpp"

class A;

class C {
    int _c;
    A* _a;
    B* _b;

public:

    C();
    C(int n);

    void set_a(A *a);
    void set_b(B *b);

    friend std::ostream& operator<<(std::ostream& os, C const& c);
};
