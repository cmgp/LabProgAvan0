#include <ostream>

#include "dt_gato.hpp"

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

DtGato::DtGato(std::string const& nombre, Genero genero, float peso, float racion_diaria, TipoPelo tipo_pelo) 
    : DtMascota(nombre, genero, peso, racion_diaria), _tipo_pelo(tipo_pelo) { }

DtGato::DtGato(Gato const& g) 
    : DtMascota(g.nombre(), g.genero(), g.peso(), g.obtenerRacionDiaria()), _tipo_pelo(g.tipo_pelo()) { }

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── GETTERS ────────────────────────────────────────────────────────────────────
//

TipoPelo DtGato::tipo_pelo() const {
    return _tipo_pelo;
}

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── METODOS ────────────────────────────────────────────────────────────────────
//

void DtGato::print(std::ostream& os) const {
    DtMascota::print(os);
    os << "Tipo de Pelo: " << tipo_pelo() << "\n";
}

// ────────────────────────────────────────────────────────────────────────────────
