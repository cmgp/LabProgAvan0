#pragma once

#include "raza_perro.hpp"
#include "dt_mascota.hpp"
#include "perro.hpp"

class DtPerro : public DtMascota
{
private:
    RazaPerro _raza;
    bool _vacuna_cachorro;
    
public:
    DtPerro(std::string const& nombre, Genero genero, float peso, float racion_diaria, RazaPerro raza, bool vacuna_cachorro);
    DtPerro(Perro const& p);

    RazaPerro raza() const;
    bool vacuna_cachorro() const;

protected: 
    virtual void print(std::ostream& os) const override;
};