#include "dt_perro.hpp"

#include <ostream>

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

DtPerro::DtPerro(std::string const& nombre, Genero genero, float peso, float racion_diaria, RazaPerro raza, bool vacuna_cachorro)
    : DtMascota(nombre, genero, peso, racion_diaria), _raza(raza), _vacuna_cachorro(vacuna_cachorro) { }

DtPerro::DtPerro(Perro const& p)
    : DtMascota(p.nombre(), p.genero(), p.peso(), p.obtenerRacionDiaria()), _raza(p.raza()), _vacuna_cachorro(p.vacuna_cachorro()) { }
    
// ────────────────────────────────────────────────────────────────────────────────

//
// ─── GETTERS ────────────────────────────────────────────────────────────────────
//

RazaPerro DtPerro::raza() const {
    return _raza;
}

bool DtPerro::vacuna_cachorro() const {
    return _vacuna_cachorro;
}

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── METODOS ────────────────────────────────────────────────────────────────────
//

void DtPerro::print(std::ostream& os) const {
    DtMascota::print(os);
    os << "Tiene vacuna del Cachorro: " << (vacuna_cachorro()? "Si" : "No") << "\n";
}

// ────────────────────────────────────────────────────────────────────────────────
    