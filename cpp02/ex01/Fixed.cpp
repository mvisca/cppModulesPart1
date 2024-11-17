#include <cmath>
#include <iostream> 
#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Fixed constructor default llamado" << std::endl;
}

// Constructor por copia
Fixed::Fixed(const Fixed& other) {
	std::cout  << "Fixed constructor por copia llamado" << std::endl;
	*this = other;
}

// Constructor con parámetro int
Fixed::Fixed(int input) {
	std::cout << "Fixed constructor con parámetro int llamado" << std::endl;
	this->_fixedPointValue = roundf(input << _fractionalBits);
}

// Constructor con parámetro float
Fixed::Fixed(float input) {
	std::cout << "Fixed constructor con parámetro float llamado" << std::endl;
	this->_fixedPointValue = roundf(input * (1 << _fractionalBits));
}

// Operador de asignación por copia
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Operator de asignacion llamado" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor llamado" << std::endl;
}

// Convertir punto fijo a float
float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Convertir punto fijo a int
int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

// Gettea el valor crudo del número de punto fijo
int Fixed::getRawBits(void) const {
	std::cout << "Fixed función miembro getRawBits llamada" << std::endl;
	return this->_fixedPointValue;
}

// Settea el valor crudo del número de punto fijo
void Fixed::setRawBits(int const raw) {
	std::cout << "Fixed función miembro setRawBits llamada" << std::endl;
	this->_fixedPointValue = raw;
}


// Acceso friend a la clase std::ostream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}