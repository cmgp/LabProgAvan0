#pragma once

#include "dt_mascota.hpp"
#include "tipo_pelo.hpp"
#include "gato.hpp"

class DtGato : public DtMascota {
    TipoPelo _tipo_pelo;

public:
    DtGato(std::string const& nombre, Genero genero, float peso, float racion_diaria, TipoPelo tipo_pelo);
    DtGato(Gato const& g);
    TipoPelo tipo_pelo() const;

protected:
    virtual void print(std::ostream& os) const override;
};