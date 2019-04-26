#pragma once

#include <iosfwd> 

enum class Genero {
    Macho, Hembra
};

std::ostream& operator<<(std::ostream& os, Genero const genero);