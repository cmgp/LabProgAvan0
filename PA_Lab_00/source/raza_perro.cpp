#include <ostream>

#include "raza_perro.hpp"

std::ostream& operator<<(std::ostream& os, RazaPerro const raza) {
    switch (raza)
    {
        case RazaPerro::Bulldog:
            os << "Bulldog";
            break;
        
        case RazaPerro::Collie:
            os << "Collie";
            break;

        case RazaPerro::Labrador:
            os << "Labrador";
            break;

        case RazaPerro::Ovejero:
            os << "Ovejero";
            break;

        case RazaPerro::Pekines:
            os << "Pekines";
            break;

        case RazaPerro::Pitbull:
            os << "Pitbull";
            break;

        default:
            os << "Otro";
            break;
    }

    return os;
}