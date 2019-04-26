#include <ostream>

#include "genero.hpp"


std::ostream& operator<<(std::ostream& os, Genero const genero) {
    switch (genero)
    {
        case Genero::Hembra:
            os << "Hembra";
            break;
        
        case Genero::Macho:
            os << "Macho";
            break;

        default:
            break;
    }

    return os;
}