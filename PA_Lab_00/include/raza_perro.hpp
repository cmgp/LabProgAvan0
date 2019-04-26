#pragma once

#include <iosfwd>

enum class RazaPerro {
    Labrador, Ovejero, Bulldog, Pitbull, Collie, Pekines, Otro
};

std::ostream& operator<<(std::ostream& os, RazaPerro const raza);