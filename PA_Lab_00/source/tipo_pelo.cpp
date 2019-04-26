#include <ostream>

#include "tipo_pelo.hpp"

std::ostream& operator<<(std::ostream& os, TipoPelo const tipo_pelo) {
    switch (tipo_pelo)
    {
        case TipoPelo::Corto:
            os << "Corto";
            break;
        
        case TipoPelo::Mediano:
            os << "Mediano";
            break;

        case TipoPelo::Largo:
            os << "Largo";
            break;

        default:
            break;
    }

    return os;
}