#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "socio.hpp"

/**
 * Dada una string, la tokeniza segun un delimitador dado.
*/
std::vector<std::string> split(std::string const& str, char delimiter);

/**
 * Obtiene el resto de los caracteres en el standard input y los descarta
*/
void flush_cin();

/**
 * Descarta los caracteres en el standard input y resetea el failbit de cin 
*/
void flush_and_clear_cin();

/**
 * Espera a que el usuario presione la tecla Enter
*/
void wait_for_return();

int pedir_opcion(int max);

int pedir_opcion(int min, int max);

DtFecha pedir_fecha(std::string const& msg);

std::string pedir_string(std::string const& msg);

DtMascota* pedir_mascota(std::string const& msg = "");


template<class T>
void print_ptr_array(T** arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << *arr[i] << "\n";
    }
}