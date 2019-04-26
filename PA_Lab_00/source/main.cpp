#include <iostream>
#include <limits>
#include <string>

#include "dt_consulta.hpp"
#include "dt_perro.hpp"
#include "dt_gato.hpp"
#include "perro.hpp"
#include "socio.hpp"
#include "gato.hpp"
#include "consulta.hpp"
#include "utils.hpp"

constexpr int MAX_SOCIOS = 50;

Socio *socios[MAX_SOCIOS];
int cant_socios = 0;

/* ────────────────────────────────────────────────────────────────────────── */
/*                                DECLARACIONES                               */
/* ────────────────────────────────────────────────────────────────────────── */
void registrarSocio(std::string ci, std::string nombre, DtMascota const& dtMascota);

void agregarMascota(std::string ci, DtMascota const& dtMascota);

void ingresarConsulta(std::string motivo, std::string ci);

DtConsulta** verConsultasAntesDeFecha(DtFecha const& fecha, std::string ciSocio, int& cantConsultas);

void eliminarSocio(std::string ci);

DtMascota** obtenerMascotas(std::string ci, int& cantMascotas);
/* ────────────────────────────────────────────────────────────────────────── */
Socio* find_socio(std::string const& ci);

int find_socio_index(std::string const& ci);
/* ────────────────────────────────────────────────────────────────────────── */


/* ────────────────────────────────────────────────────────────────────────── */
/*                                    MAIN                                    */
/* ────────────────────────────────────────────────────────────────────────── */

int main(int argc, char** args) {
    int opcion;
    do {
        system("clear");
        std::cout << "Bienvenido. Seleccione una opcion:\n"
            << "\t[1] - Registrar socio\n"
            << "\t[2] - Agregar mascota\n"
            << "\t[3] - Ingresar consulta\n"
            << "\t[4] - Ver consultas\n"
            << "\t[5] - Eliminar socio\n"
            << "\t[6] - Ver mascotas\n\n"
            << "\t[0] - Salir\n";

        try {
            opcion = pedir_opcion(6);

            system("clear");
            if(opcion == 1) {
                std::cout << "==========Registro de Socio==========\n";

                if(cant_socios == MAX_SOCIOS) {
                    throw std::length_error("No se pueden registrar mas socios.");
                }

                std::string ci = pedir_string("Ingrese la cedula del socio a registrar.");

                std::string nombre = pedir_string("Ingrese el nombre del socio.");

                DtMascota* dt_mascota = pedir_mascota();

                registrarSocio(ci, nombre, *dt_mascota);

                delete dt_mascota;
            }
            else if(opcion == 2) {
                std::cout << "==========Agregar Mascota==========\n";

                if(cant_socios == 0) {
                    std::cout << "\nNo hay socios registrados en el sistema.\n";
                    wait_for_return();
                    continue;
                }

                std::string ci = pedir_string("Ingrese la cedula del socio.");

                DtMascota* dt_mascota = pedir_mascota();

                agregarMascota(ci, *dt_mascota);

                delete dt_mascota;
            }
            else if(opcion == 3) {
                std::cout << "==========Ingreso de consulta==========\n";

                if(cant_socios == 0) {
                    std::cout << "\nNo hay socios registrados en el sistema.\n";
                    wait_for_return();
                    continue;
                }

                std::string ci = pedir_string("Ingrese la cedula del socio.");


                std::string motivo = pedir_string("Ingrese el motivo de la consulta.");

                ingresarConsulta(motivo, ci);

                std::cout << "Consulta ingresada con exito.\n\n";
                wait_for_return();
            }
            else if(opcion == 4) {
                std::cout << "==========Ver Consultas==========\n";

                if(cant_socios == 0) {
                    std::cout << "\nNo hay socios registrados en el sistema.\n";
                    wait_for_return();
                    continue;
                }

                int cant_consultas = 0;
                DtFecha fecha = pedir_fecha("Ingrese la fecha a consultar ( DD/MM/AAAA )");
                std::string cedula = pedir_string("Ingrese la cedula del socio");
                DtConsulta **consultas = verConsultasAntesDeFecha(fecha, cedula, cant_consultas);

                if(cant_consultas == 0) {
                    std::cout << "El socio no tiene consultas antes de " << fecha << "\n";
                    wait_for_return();
                    continue;
                }

                for(int i = 0; i < cant_consultas; ++i) {
                    std::cout << *consultas[i] << "\n";
                    delete consultas[i];
                }

                delete[] consultas;
                wait_for_return();
            }
            else if(opcion == 5) {
                std::cout << "==========Borrar Socio==========\n";

                if(cant_socios == 0) {
                    std::cout << "\nNo hay socios registrados en el sistema.\n";
                    wait_for_return();
                    continue;
                }

                std::string ci = pedir_string("Ingrese la cedula del socio a borrar.");

                eliminarSocio(ci);

                std::cout << "El socio ha sido eliminado exitosamente.\n";
                wait_for_return();
            }
            else if(opcion == 6) {
                std::cout << "==========Ver Mascotas==========\n";

                if(cant_socios == 0) {
                    std::cout << "\nNo hay socios registrados en el sistema.\n";
                    wait_for_return();
                    continue;
                }

                std::string ci = pedir_string("Ingrese la cedula del socio.");
                int cant_mascotas = 0;
                DtMascota **mascotas = obtenerMascotas(ci, cant_mascotas);

                for(int i = 0; i < cant_mascotas; ++i) {
                    std::cout << *mascotas[i] << "\n";
                }

                wait_for_return();
            }
        }
        catch(std::exception& e) {
            std::cout << "Error: " << e.what() << "\n\n";
            wait_for_return();
        }
    } while(opcion != 0);
}


/* ────────────────────────────────────────────────────────────────────────── */
/*                            FUNCIONES REQUERIDAS                            */
/* ────────────────────────────────────────────────────────────────────────── */

void registrarSocio(std::string ci, std::string nombre, DtMascota const& dtMascota) {
    if(find_socio(ci)) {
        throw std::invalid_argument("Ya se encuentra un socio registrado con esa cedula.");
    }

    DtFecha fecha = pedir_fecha("Ingrese la fecha en la que se registrara el socio. ( DD/MM/AAAA )");

    Mascota *mascota = nullptr;

    if(DtPerro const* dt_perro = dynamic_cast<DtPerro const*>(&dtMascota))
        mascota = new Perro(dt_perro->nombre(), dt_perro->genero(), dt_perro->peso(), dt_perro->raza(), dt_perro->vacuna_cachorro());
    else if(DtGato const* dt_g = dynamic_cast<DtGato const*>(&dtMascota))
        mascota = new Gato(dt_g->nombre(), dt_g->genero(), dt_g->peso(), dt_g->tipo_pelo());

    socios[cant_socios++] = new Socio(ci, nombre, fecha, mascota);

    wait_for_return();
}

void agregarMascota(std::string ci, DtMascota const& dt) {
    Socio* socio = find_socio(ci);

    if(!socio) {
        throw std::invalid_argument("El socio no existe en el sistema.");
    }

    socio->agregar_mascota(dt);
}

void ingresarConsulta(std::string motivo, std::string ci) {
    Socio* socio = find_socio(ci);

    if(!socio)
        throw std::invalid_argument("El socio no existe en el sistema.");

    DtFecha fecha = pedir_fecha("Ingrese una fecha para la consulta. (DD/MM/AAAA)");

    socio->agregar_consulta(fecha, motivo);
}


DtConsulta** verConsultasAntesDeFecha(DtFecha const& fecha, std::string ciSocio, int& cantConsultas) {
    Socio *socio = find_socio(ciSocio);

    if(!socio)
        throw std::invalid_argument("El socio no existe en el sistema.");

    //Guardamos suficiente espacio como para la maxima cantidad de consultas posibles;
    DtConsulta **consultas = new DtConsulta*[socio->cant_consultas()];
    int j = 0;
    for(int i = 0; i < socio->cant_consultas(); ++i) {
        if(socio->consultas()[i]->fecha() < fecha) {
            consultas[j++] = new DtConsulta(*socio->consultas()[i]);
            ++cantConsultas;
        }
    }

    if(cantConsultas == 0) {
        delete[] consultas;
        return nullptr;
    }

    return consultas;
}

void eliminarSocio(std::string ci) {
    int index = find_socio_index(ci);

    if(index < 0) {
        throw std::invalid_argument("El socio ingresado no existe en el sistema.");
    }

    delete socios[index]; // Se borra el socio.
    --cant_socios;
    socios[index] = socios[cant_socios]; // Se pasa el puntero del ultimo socio del array al espacio vacio que quedo.
    socios[cant_socios] = nullptr; // Se borra el puntero repetido que quedaria en el ultimo lugar.
}

DtMascota** obtenerMascotas(std::string ci, int& cantMascotas) {
    Socio *socio = find_socio(ci);
    if(!socio) {
        throw std::invalid_argument("El socio ingresado no existe en el sistema.");
    }

    cantMascotas = socio->cant_mascotas();
    if(cantMascotas == 0) {
        return nullptr;
    }

    Mascota const * const * mascotas = socio->mascotas();
    DtMascota **dt_mascotas = new DtMascota*[cantMascotas];

    for(int i = 0; i < cantMascotas; ++i) {
        if(Perro const* p = dynamic_cast<Perro const*>(mascotas[i])) {
            dt_mascotas[i] = new DtPerro(*p);
        }
        else {
            Gato const* g = dynamic_cast<Gato const*>(mascotas[i]);
            dt_mascotas[i] = new DtGato(*g);
        }
    }

    return dt_mascotas;
}

/* ────────────────────────────────────────────────────────────────────────── */
/*                            FUNCIONES DE UTILIDAD                           */
/* ────────────────────────────────────────────────────────────────────────── */

Socio* find_socio(std::string const& ci) {
    int index = find_socio_index(ci);
    if(index >= 0)
        return socios[index];

    return nullptr;
}

int find_socio_index(std::string const& ci) {
    for(int i = 0; i < cant_socios; ++i) {
        if(socios[i]->ci() == ci) {
            return i;
        }
    }

    return -1;
}
