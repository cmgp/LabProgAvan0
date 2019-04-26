#pragma once

#include <iosfwd>

class A;
class C;

class B {
    int _b;
    A* _a;
    C* _c;

public:

    B();
    B(int n);

    void set_a(A *a);
    void set_c(C *c);

    friend std::ostream& operator<<(std::ostream&, B const& b);
};
