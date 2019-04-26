#include <utility>

#include "consulta.hpp"
#include "dt_consulta.hpp"

/* ────────────────────────────────────────────────────────────────────────── */
/*                                CONSTRUCTORES                               */
/* ────────────────────────────────────────────────────────────────────────── */

Consulta::Consulta(DtFecha const& fecha, std::string const& motivo)
    : _fecha(fecha), _motivo(motivo) { }

// ────────────────────────────────────────────────────────────────────────── //


/* ────────────────────────────────────────────────────────────────────────── */
/*                                   GETTERS                                  */
/* ────────────────────────────────────────────────────────────────────────── */

std::string const& Consulta::motivo() const {
    return _motivo;
}

DtFecha const& Consulta::fecha() const {
    return _fecha;
}

/* ────────────────────────────────────────────────────────────────────────── */


/* ────────────────────────────────────────────────────────────────────────── */
/*                                   SETTERS                                  */
/* ────────────────────────────────────────────────────────────────────────── */

void Consulta::set_motivo(std::string motivo) {
    _motivo = std::move(motivo);
}

void Consulta::set_fecha(DtFecha const& fecha) {
    _fecha = fecha;
}

/* ────────────────────────────────────────────────────────────────────────── */
