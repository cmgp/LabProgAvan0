#pragma once

#include <string>

#include "genero.hpp"

class Mascota {
private:
    std::string _nombre;
    Genero _genero;
    float _peso;

public:
    Mascota(Mascota&& other);
    Mascota(std::string const& nombre, Genero genero, float peso);

    std::string const& nombre() const;
    Genero genero() const;
    float peso() const;

    virtual float obtenerRacionDiaria() const = 0;
};