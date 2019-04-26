#include "perro.hpp"

Perro::Perro(std::string const& nombre, Genero genero, float peso, RazaPerro raza, bool vacuna_cachorro)
    : Mascota(nombre, genero, peso), _raza(raza), _vacuna_cachorro(vacuna_cachorro) { }


RazaPerro Perro::raza() const  {
    return _raza;
}

bool Perro::vacuna_cachorro() const {
    return _vacuna_cachorro;
}

float Perro::obtenerRacionDiaria() const {
    return peso() * 1000 * 0.025;
}