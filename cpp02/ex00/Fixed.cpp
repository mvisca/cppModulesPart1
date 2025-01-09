#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Ex00
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// Settea el valor crudo del número de punto fijo
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}