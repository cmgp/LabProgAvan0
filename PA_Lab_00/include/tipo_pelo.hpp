#pragma once

#include <iosfwd>

enum class TipoPelo {
    Corto, Mediano, Largo
};

std::ostream& operator<<(std::ostream& os, TipoPelo const tipo_pelo);