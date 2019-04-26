#include "gato.hpp"

Gato::Gato(std::string const& nombre, Genero genero, float peso, TipoPelo tipo_pelo)
    : Mascota(nombre, genero, peso), _tipo_pelo(tipo_pelo) { }

TipoPelo Gato::tipo_pelo() const {
    return _tipo_pelo;
}

float Gato::obtenerRacionDiaria() const {
    return peso() * 1000 * 0.015;
}