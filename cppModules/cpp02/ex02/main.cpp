#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;

	std::cout << "a con default constructor: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;

	std::cout << std::endl;

	Fixed b (42.24f);
	Fixed c = b;

	std::cout << std::endl;

	std::cout << "max (a, b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min (a, c): " << Fixed::min( a, c ) << std::endl;

	std::cout << std::endl;

	std::cout << "a > c: " << ((a > c) ? "true" : "false");
	std::cout << "a < c: " << ((a < c) ? "true" : "false");
	std::cout << "a == c: " << ((a == c) ? "true" : "false");
	std::cout << "a == a: " << ((a == a) ? "true" : "false");
	std::cout << "a != c: " << ((a != c) ? "true" : "false");
	std::cout << "a != a: " << ((a != a) ? "true" : "false");

	std::cout << std::endl;

	std::cout << "a + c: " << a << " + " << c << " = " << a + c << std::endl;
	std::cout << "a - c: " << a << " - " << c << " = " << a - c << std::endl;
	std::cout << "a - c: " << a << " - " << c << " = " << a - c << std::endl;
	std::cout << "a / 0: " << a << " / 0 " << " = " << a / 0 << std::endl;
	std::cout << "a / c: " << a << " / " << c << " = " << a / c << std::endl;
	std::cout << "a * c: " << a << " * " << c << " = " << a * c << std::endl;

	std::cout << std::endl;

	return 0;
}