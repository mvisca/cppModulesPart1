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

		// Constructor con parámetro int
		Fixed(int input);

		// Constructor con parámetro float
		Fixed(float input);

		// Operador de asignación por copia
		Fixed& operator=(const Fixed& other);


		// Destructor
		~Fixed();

		// Convertir a float
		float toFloat(void) const;

		// Convertir a int
		int toInt(void) const;

		// Getter del valor crudo
		int getRawBits(void) const;

		// Setter del valor crudo
		void setRawBits(const int raw);

};

	// Operador de inserción
	std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed);

#endif