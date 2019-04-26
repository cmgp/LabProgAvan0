#include <stdexcept>

#include "socio.hpp"
#include "perro.hpp"
#include "gato.hpp"
#include "dt_perro.hpp"
#include "dt_gato.hpp"

/* ────────────────────────────────────────────────────────────────────────── */
/*                         CONSTRUCTORES Y DESTRUCTOR                         */
/* ────────────────────────────────────────────────────────────────────────── */

Socio::Socio(std::string const& ci, std::string const& nombre, DtFecha const& fecha_ingreso, Mascota* mascota)
    : _ci(ci), _nombre(nombre), _fecha_ingreso(fecha_ingreso), _cant_mascotas(0), _cant_consultas(0){

    if(mascota == nullptr)
        throw std::invalid_argument("La mascota no es valida.\n");
    else
        _mascotas[_cant_mascotas++] = mascota;
}

Socio::~Socio() {
    for(int i = 0; i < _cant_mascotas; ++i) {
        delete _mascotas[i];
    }

    for(int i = 0; i < _cant_consultas; ++i) {
        delete _consultas[i];
    }
}

/* ────────────────────────────────────────────────────────────────────────── */
/*                                   GETTERS                                  */
/* ────────────────────────────────────────────────────────────────────────── */

std::string const& Socio::ci() const {
    return _ci;
}

std::string const& Socio::nombre() const {
    return _nombre;
}

DtFecha const& Socio::fecha_ingreso() const {
    return _fecha_ingreso;
}

Consulta const *const * Socio::consultas() const {
    return _consultas;
}

Mascota const *const * Socio::mascotas() const {
    return _mascotas;
}

int Socio::cant_consultas() const {
    return _cant_consultas;
}

int Socio::cant_mascotas() const {
    return _cant_mascotas;
}

/* ────────────────────────────────────────────────────────────────────────── */
/*                                   METODOS                                  */
/* ────────────────────────────────────────────────────────────────────────── */

void Socio::agregar_consulta(DtConsulta const& dt_con) {
    agregar_consulta(dt_con.fecha(), dt_con.motivo());
}

void Socio::agregar_consulta(DtFecha const& fecha, std::string const& motivo) {
    if(_cant_consultas >= MAX_CONSULTAS) {
        throw std::length_error("El socio ya tiene la maxima cantidad de consultas.\n");
    }

    _consultas[_cant_consultas++] = new Consulta(fecha, motivo);
}

void Socio::agregar_consulta(Consulta *con) {
    if(_cant_consultas >= MAX_CONSULTAS) {
        throw std::length_error("El socio ya tiene la maxima cantidad de consultas.\n");
    }

    _consultas[_cant_consultas++] = con;
}

void Socio::agregar_mascota(DtMascota const& dtm) {
    if(_cant_mascotas == MAX_MASCOTAS)
        throw std::length_error("El socio ya tiene el maximo de mascotas registradas.");

    Mascota* mascota = nullptr;

    if(DtPerro const* dtp = dynamic_cast<DtPerro const*>(&dtm))
        mascota = new Perro(dtp->nombre(), dtp->genero(), dtp->peso(), dtp->raza(), dtp->vacuna_cachorro());
    else if(DtGato const* dtg = dynamic_cast<DtGato const*>(&dtm))
        mascota = new Gato(dtg->nombre(), dtg->genero(), dtg->peso(), dtg->tipo_pelo());
    else { // No es ni Perro ni Gato
        throw std::invalid_argument("La mascota no es Gato o Perro");
    }

    _mascotas[_cant_mascotas++] = mascota;
}

void Socio::agregar_mascota(Mascota *mas) {
    if(!mas)
        throw std::invalid_argument("La mascota no es valida.");

    if(_cant_mascotas < MAX_MASCOTAS)
        _mascotas[_cant_mascotas++] = mas;
    else
        throw std::length_error("El socio ya tiene el maximo de mascotas registradas.");
}

/* ────────────────────────────────────────────────────────────────────────── */
/*                                  OVERLOADS                                 */
/* ────────────────────────────────────────────────────────────────────────── */

std::ostream& operator<<(std::ostream& os, Socio const& s) {
    return os << "Cedula: " << s.ci() << "\n"
       << "Nombre: " << s.nombre() << "\n"
       << "Fecha ingreso: " << s.fecha_ingreso() << "\n"
       << "Cant mascotas: " << s.cant_mascotas() << "\n"
       << "Cant consultas: " << s.cant_consultas() << "\n";
}