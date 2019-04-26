#include <ostream>

#include "dt_fecha.hpp"

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

DtFecha::DtFecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}


// ────────────────────────────────────────────────────────────────────────────────


//
// ─── GETTERS ────────────────────────────────────────────────────────────────────
//

int DtFecha::dia() const {
    return _dia;
}

int DtFecha::mes() const {
    return _mes;
}

int DtFecha::anio() const {
    return _anio;
}

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── OVERLOADS ──────────────────────────────────────────────────────────────────
//

std::ostream& operator<<(std::ostream& os, DtFecha const& fecha) {
    if(fecha.dia() < 10)
        os << "0";

    os << fecha.dia() << "/";

    if(fecha.mes() < 10)
        os << "0";

    os << fecha.mes() << "/" << fecha.anio();
}

bool DtFecha::operator<(DtFecha const& otra) const {
    if(_anio < otra._anio)
        return true;

    if(_anio > otra._anio)
        return false;

    if(_mes < otra._mes)
        return true;

    if(_mes > otra._mes)
        return false;

    if(_dia < otra._dia)
        return true;
    else
        return false; //_dia mayor o igual a otra._dia
}