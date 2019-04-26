#pragma once

#include "mascota.hpp"
#include "tipo_pelo.hpp"

class Gato : public Mascota
{
private:
    TipoPelo _tipo_pelo;

public:
    Gato(std::string const& nombre, Genero genero, float peso, TipoPelo tipo_pelo);

    TipoPelo tipo_pelo() const;

    virtual float obtenerRacionDiaria() const override;
};

