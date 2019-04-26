#pragma once
#include <string>
#include <ostream>

#include "dt_fecha.hpp"
#include "mascota.hpp"
#include "consulta.hpp"
#include "dt_consulta.hpp"
#include "dt_mascota.hpp"

class Socio {
private:
    static int constexpr MAX_MASCOTAS = 10;
    static int constexpr MAX_CONSULTAS = 20;

    std::string _ci;
    std::string _nombre;
    DtFecha _fecha_ingreso;

    Mascota* _mascotas[MAX_MASCOTAS];
    int _cant_mascotas;

    Consulta* _consultas[MAX_CONSULTAS];
    int _cant_consultas;

public:
    Socio(std::string const& ci, std::string const& nombre, DtFecha const& fecha_ingreso, Mascota* mascota);
    ~Socio();

    std::string const& ci() const;
    std::string const& nombre() const;
    DtFecha const& fecha_ingreso() const;

    Consulta const * const * consultas() const;
    Mascota const * const * mascotas() const;
    int cant_consultas() const;
    int cant_mascotas() const;

    void agregar_consulta(DtConsulta const& dt_con);
    void agregar_consulta(DtFecha const& fecha, std::string const& motivo);
    void agregar_consulta(Consulta *con);

    void agregar_mascota(DtMascota const& dt_mas);
    void agregar_mascota(Mascota *mas);
};

std::ostream& operator<<(std::ostream& os, Socio const& s);