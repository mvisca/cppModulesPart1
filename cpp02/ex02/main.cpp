#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	std::cout << "- Default Main -" << std::endl;

	Fixed x;
	Fixed const z( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << z << std::endl;
	std::cout << Fixed::max( x, z ) << std::endl;

	std::cout << "-------------" << std::endl;

	Fixed a;
	std::cout << "Valor de a: " << a << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Valor de b: " << b << std::endl;

	std::cout << "Valor de ++a: " << ++a << std::endl;

	std::cout << "Valor de a++: " << a++ << std::endl;
	std::cout << "Nuevo valor de a: " << a << std::endl;

	std::cout << "Valor de --a: " << --a << std::endl;

	std::cout << "Valor de a--: " << a-- << std::endl;
	std::cout << "Nuevo valor de a: " << a << std::endl;

	a = b / 2;
	std::cout << "a = b / 2: " << a << std::endl;

	std::cout << "Valor de a * 2: " << a * 2 << std::endl;
	std::cout << "Valor de a / 2: " << a / 2 << std::endl;

	std::cout << "Condición a > b: " << (a > b ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Condición a >= a: " << (a >= a ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Condición a < b: " << (a < b ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Condición b <= b: " << (b <= b ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Condición a == b: " << (a == b ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Max(a,b): " << Fixed::max( a, b ) << std::endl;

	std::cout << "Min(a,b): " << Fixed::min( a, b ) << std::endl;

	return 0;
}