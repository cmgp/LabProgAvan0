#pragma once
#include <string>

#include "dt_fecha.hpp"

class Consulta;

class DtConsulta {
private:
    DtFecha _fecha_consulta;
    std::string _motivo;

public:
    DtConsulta(DtFecha const& fecha, std::string const& motivo);
    DtConsulta(DtFecha const& fecha, std::string && motivo);
    DtConsulta(Consulta const& consulta);
    
    DtFecha const& fecha() const;
    std::string const& motivo() const;
};

std::ostream& operator<<(std::ostream& os, DtConsulta const& dt);