#include <iostream>

#include "a.hpp"
#include "b.hpp"
#include "c.hpp"

int main() {
    A a(65);
    B b(66);
    C c(67);

    a.set_b(&b);
    a.set_c(&c);

    b.set_a(&a);
    b.set_c(&c);

    c.set_a(&a);
    c.set_b(&b);

    std::cout << a << "\n" << b << "\n" << c << "\n";
}
