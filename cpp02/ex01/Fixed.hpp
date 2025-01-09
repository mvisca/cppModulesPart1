#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int _fixedPointValue;
		static const int _fractionalBits;

	public:
		
		// Ex00

		// Constructor por defecto
		Fixed();

		// Constructor de copia
		Fixed(const Fixed& other);

		// Operador de asignación por copia
		Fixed& operator=(const Fixed& other);

		// Destructor
		~Fixed();

		// Getter del valor crudo
		int getRawBits(void) const;

		// Setter del valor crudo
		void setRawBits(const int raw);

		// Ex01

		// Constructor con parámetro
		Fixed(const float input);
		Fixed(const int input);
//		Fixed(const float input);
//		Fixed(const int input);

		// Convertir a float
		float toFloat(void) const;

		// Convertir a int
		int toInt(void) const;
};

// Ex01
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif