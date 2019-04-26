#include <ostream>

#include "dt_consulta.hpp"
#include "consulta.hpp"

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

DtConsulta::DtConsulta(DtFecha const& fecha, std::string const& motivo)
    : _fecha_consulta(fecha), _motivo(motivo){ }

DtConsulta::DtConsulta(DtFecha const& fecha, std::string && motivo)
    : _fecha_consulta(fecha), _motivo(std::move(motivo)) { }

DtConsulta::DtConsulta(Consulta const& consulta)
    : _fecha_consulta(consulta.fecha()), _motivo(consulta.motivo()) { }

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── GETTERS ────────────────────────────────────────────────────────────────────
//

DtFecha const& DtConsulta::fecha() const {
    return _fecha_consulta;
}

std::string const& DtConsulta::motivo() const {
    return _motivo;
}

// ────────────────────────────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, DtConsulta const& dt) {
    return os << "Fecha de consulta: " << dt.fecha() << "\n"
       << "Motivo de consulta: " << dt.motivo() << "\n";
}