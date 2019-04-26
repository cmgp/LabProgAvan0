#include "dt_mascota.hpp"

#include <ostream>

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

DtMascota::DtMascota(std::string const& nombre, Genero genero, float peso, float racion_diaria) 
    : _nombre(nombre), _peso(peso), _genero(genero), _racion_diaria(racion_diaria) { }

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── GETTERS ────────────────────────────────────────────────────────────────────
//

std::string const& DtMascota::nombre() const {
    return _nombre;
}
    
Genero DtMascota::genero() const {
    return _genero;
}

float DtMascota::peso() const {
    return _peso;
}

float DtMascota::racion_diaria() const {
    return _racion_diaria;
}

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── METHODS ────────────────────────────────────────────────────────────────────
//

void DtMascota::print(std::ostream& os) const {
    os << "Nombre: " << nombre() << "\n"
       << "Genero: " << genero() << "\n"
       << "Peso: " <<  peso() << "kg\n"
       << "Racion Diaria: " << racion_diaria() << " gramos\n";
}

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── OVERLOADS ──────────────────────────────────────────────────────────────────
//

std::ostream& operator<<(std::ostream& os, DtMascota const& mascota) {
    mascota.print(os);
    return os;
}