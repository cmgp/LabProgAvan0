#pragma once
#include <string>
#include <iosfwd> 

#include "genero.hpp"

class DtMascota
{
private:
    std::string _nombre;
    Genero _genero;
    float _peso;
    float _racion_diaria;

public:
    DtMascota(std::string const& nombre, Genero genero, float peso, float racion_diaria);

    std::string const& nombre() const;
    Genero genero() const;
    float peso() const;
    float racion_diaria() const;

    friend std::ostream& operator<<(std::ostream& os, DtMascota const& mascota);
protected:
    virtual void print(std::ostream& os) const;
};