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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif