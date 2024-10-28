#include <cmath>
#include <iostream> 
#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructor por copia
Fixed::Fixed(const Fixed& other) {
	std::cout  << "Copy constructor called" << std::endl;
	*this = other;
}

// Constructor con parámetro
Fixed::Fixed(float input) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(input * (1 << _fractionalBits));
}

// Operador de asignación por copia
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Gettea el valor crudo del número de punto fijo
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// Settea el valor crudo del número de punto fijo
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

// Convertir punto fijo a float
float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// Convertir punto fijo a int
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Acceso friend a la clase std::ostream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}