#include <cmath>
#include <iostream> 
#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructor por copia
Fixed::Fixed(const Fixed& other) {
	std::cout  << "Copy constructor called" << std::endl;
	*this = other;
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
	return this->_fixedPointValue;
}

// Settea el valor crudo del número de punto fijo
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

// Ex01

// Constructor con parámetro float
Fixed::Fixed(const float input) {
	std::cout << "float constructor called" << std::endl;
	this->_fixedPointValue = roundf(input * (1 << _fractionalBits));
}

// Constructor con parámetro int
Fixed::Fixed(const int input) {
	std::cout << "int constructor called" << std::endl;
	this->_fixedPointValue = input << _fractionalBits;
}

// Convertir punto fijo a float
float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// Convertir punto fijo a int
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Ex 01

// Acceso friend a la clase std::ostream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}