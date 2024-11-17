#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		// Constructor por defecto
		Fixed();

		// Constructor de copia
		Fixed(const Fixed& other);

		// Constructor con parámetro
		Fixed(float input);

		// Operador de asignación por copia
		Fixed& operator=(const Fixed& other);

		// Operadores de comparación
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Operadores aritméticos
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Operadores de incremento y decremento
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		// Destructor
		~Fixed();

		// Getter del valor crudo
		int getRawBits(void) const;

		// Setter del valor crudo
		void setRawBits(int const raw);

		// Convertir a float
		float toFloat(void) const;

		// Convertir a int
		int toInt(void) const;

		// Funciones miembro estáticas
		static Fixed& min(Fixed& n1, Fixed& n2);
		static const Fixed& min(const Fixed& n1, const Fixed& n2);
		static Fixed& max(Fixed& n1, Fixed& n2);
		static const Fixed& max(const Fixed& n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif