#pragma once
#include "mascota.hpp"
#include "raza_perro.hpp"

class Perro : public Mascota {
private:
    RazaPerro _raza;
    bool _vacuna_cachorro;

public:
    Perro(std::string const& nombre, Genero genero, float peso, RazaPerro raza, bool vacuna_cachorro);

    RazaPerro raza() const;
    bool vacuna_cachorro() const;

    virtual float obtenerRacionDiaria() const override;
};