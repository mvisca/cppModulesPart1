#include <iostream>
#include "Fixed.hpp"

int main() {
    // Crea un Fixed a partir de un float 42.24f
    std::cout << "Creando un objeto Fixed (a) a partir de un float (42.24f):" << std::endl;
    Fixed a(42.24f);
    std::cout << "Fixed a (usando por primera vez el overload de operador de inserción): " << a << std::endl;

    std::cout << "----------" << std::endl;

    // Crea un Fixed a partir de un int 84
    std::cout << "Creando un objeto Fixed (b) a partir de un int (84):" << std::endl;
    Fixed b(84);
    std::cout << "Fixed b: " << b << std::endl;

    std::cout << "----------" << std::endl;

    // Crea copias de los objetos anteriores e imprimirlas
    std::cout << "Creando copias de (a) y (b):" << std::endl;
    Fixed aCopy(a);
    Fixed bCopy(b);
    std::cout << "Copia de a: " << aCopy << std::endl;
    std::cout << "Copia de b: " << bCopy << std::endl;
  
    std::cout << "----------" << std::endl;

    // Crea un Fixed con el constructor por defecto y le asigna del float 22.22f
    std::cout << "Creando un objeto Fixed con el constructor por defecto:" << std::endl;
    Fixed c;
    std::cout << "Fixed d por defecto: " << c << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "Asignando 22.22f a c:" << std::endl;
    c = Fixed(17.71f);
    std::cout << "Fixed c después de la asignación: " << c << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << "Salida" << std::endl;

    return 0;
}
