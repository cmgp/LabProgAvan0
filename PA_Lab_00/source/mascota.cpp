#include "mascota.hpp"

Mascota::Mascota(std::string const& nombre, Genero genero, float peso)
    : _nombre(nombre), _genero(genero), _peso(peso) { }

Mascota::Mascota(Mascota&& other)
    : _nombre(std::move(other._nombre)), _genero(other._genero), _peso(other._peso) { }

float Mascota::peso() const {
    return _peso;
}

std::string const& Mascota::nombre() const {
    return _nombre;
}

Genero Mascota::genero() const {
    return _genero;
}