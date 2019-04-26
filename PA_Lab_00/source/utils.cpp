#include "utils.hpp"

#include <iostream>
#include <sstream>

#include "dt_perro.hpp"
#include "dt_gato.hpp"

std::vector<std::string> split(std::string const& str, char delimiter) {
    std::vector<std::string> tokens;

    std::string token;
    std::istringstream token_stream(str);
    while (std::getline(token_stream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

void flush_cin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void flush_and_clear_cin() {
    std::cin.clear();
    flush_cin();
}

void wait_for_return() {
    std::cout << "Presione [ENTER] para continuar...";
    std::cin.get();
}

int pedir_opcion(int max) {
    return pedir_opcion(0, max);
}

int pedir_opcion(int min, int max) {
    int opcion;

    do {
        std::cout << "> ";
        std::cin >> opcion;

        if(!std::cin) {
            std::cout << "Entrada invalida.\n\n";
            flush_and_clear_cin();
            opcion = -1;
        }
        else if(opcion < min || opcion > max) {
            std::cout << "Entrada invalida, ingrese una opcion entre " << min << " y " << max << ".\n\n";
        }
    } while(opcion < min || opcion > max);

    flush_cin();
    return opcion;
}

DtFecha pedir_fecha(std::string const& msg) {
    int dia, mes, anio;

    std::string fecha_str = pedir_string(msg);

    std::vector<std::string> datos = split(fecha_str, '/');
    dia = std::stoi(datos[0]);
    mes = std::stoi(datos[1]);
    anio = std::stoi(datos[2]);

    return DtFecha{dia, mes, anio};
}

std::string pedir_string(std::string const& msg) {
    std::string out;

    std::cout << msg << "\n\n";
    std::cout << "> ";
    std::getline(std::cin, out);
    std::cout << "\n";

    return out;
}

DtMascota* pedir_mascota(std::string const& msg) {
    std::string tipo_mascota = pedir_string("Ingrese el tipo de mascota a registar. [Gato|Perro]");

    std::string nombre = pedir_string("Ingrese el nombre de la mascota.");

    std::string str_genero = pedir_string("Ingrese el genero de la mascota. [Macho|Hembra]");
    Genero genero;

    if(str_genero == "Macho") {
        genero = Genero::Macho;
    }
    else
    {
        genero = Genero::Hembra;
    }

    float peso;
    std::cout << "Ingrese el peso de la mascota.\n\n"
              << "> ";
    std::cin >> peso;
    flush_cin();
    std::cout << "\n";

    if(tipo_mascota == "Gato") {
        std::string str_tipo_pelo = pedir_string("Ingrese el tipo de pelo del gato. [Corto|Largo|Mediano]");
        TipoPelo tipo_pelo;

        if(str_tipo_pelo == "Corto") {
            tipo_pelo = TipoPelo::Corto;
        }
        else if(str_tipo_pelo == "Largo")
        {
            tipo_pelo = TipoPelo::Largo;
        }
        else {
            tipo_pelo = TipoPelo::Mediano;
        }

        return new DtGato(nombre, genero, peso, 0, tipo_pelo);
    }
    else {
        std::string str_raza = pedir_string("Ingrese la raza del perro. [Bulldog|Collie|Labrador|Ovejero|Pekines|Pitbul|Otro]");
        RazaPerro raza;

        if(str_raza == "Bulldog") {
            raza = RazaPerro::Bulldog;
        }
        else if(str_raza == "Collie")
        {
            raza = RazaPerro::Collie;
        }
        else if(str_raza == "Labrador")
        {
            raza = RazaPerro::Labrador;
        }
        else if(str_raza == "Ovejero")
        {
            raza = RazaPerro::Ovejero;
        }
        else if(str_raza == "Pekines")
        {
            raza = RazaPerro::Pekines;
        }
        else if(str_raza == "Pitbul")
        {
            raza = RazaPerro::Pitbull;
        }
        else {
            raza = RazaPerro::Otro;
        }

        std::string str_vacuna = pedir_string("El perro tiene vacuna de cachorro? [S/N]");
        bool vacuna = str_vacuna == "S";

        return new DtPerro(nombre, genero, peso, 0, raza, vacuna);
    }
}