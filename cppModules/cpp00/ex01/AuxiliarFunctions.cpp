#include "GlobalHeader.hpp"

std::string toUppercase(std::string str) {

    size_t      strlen = str.length();
    std::string aux(strlen, '\0');

    for (size_t i = 0; i < strlen; i++) {
        aux[i] = std::toupper(str[i]);
    }
    return aux;
}