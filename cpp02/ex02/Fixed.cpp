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
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

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

// Operador de asignación por copia
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Operadores de comparación

bool Fixed::operator<(const Fixed& other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

// Operadores aritméticos

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (other._fixedPointValue != 0) {
		result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	} else {
		std::cerr << "Error: División by zero" << std::endl;
		result.setRawBits(0);
	}
	return result;
}

// Operadores de incremento y decremento

Fixed& Fixed::operator++() {
	this->_fixedPointValue += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	this->_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue += 1;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue -= 1;
	return temp;
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

// Convertir punto fijo a float
float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// Convertir punto fijo a int
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Devolver el mínimo
Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
	return (n1 < n2) ? n1 : n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
	return (n1 < n2) ? n1 : n2;
}

// Devolver el máximo
Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	return (n1 > n2) ? n1 : n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
	return (n1 > n2) ? n1 : n2;
}

// Ex 01

// Acceso friend a la clase std::ostream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}