#pragma once

#include <iosfwd>

class DtFecha {
private:
    int _dia, _mes, _anio;

public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);

    int dia() const;
    int mes() const;
    int anio() const;

    bool operator<(DtFecha const& otra) const;
    
    friend std::ostream& operator<<(std::ostream& os, DtFecha const& fecha);
};