#pragma once
#include <string>

#include "dt_fecha.hpp"

class Consulta {
private:
    DtFecha _fecha;
    std::string _motivo;

public:
    Consulta(DtFecha const& fecha, std::string const& motivo);

    // TODO Ver si esto tiene sentido para todos los casos, o es mejor retornar por valor
    std::string const& motivo() const;
    DtFecha const& fecha() const;

    void set_motivo(std::string motivo);
    void set_fecha(DtFecha const& fecha);
};