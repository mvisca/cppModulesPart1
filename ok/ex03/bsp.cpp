#include "Fixed.hpp"
#include "Point.hpp"

// Función auxiliar para calcular el producto vectorial
Fixed crossProduct(Point const p1, Point const p2, Point const p3) {
	Fixed result = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
	return result;
}

// bsp devuelve true si 'point' está dentro el triángulo 'a-b-c'
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	 // Calcula los productos vectoriales para determinar la posición relativa del punto
	 Fixed cross1 = crossProduct(a, b, point);
	 Fixed cross2 = crossProduct(b, c, point);
	 Fixed cross3 = crossProduct(c, a, point);

	 // Valida que los tres tienen mismo signo
	 bool isPositive = (cross1 > 0 && cross2 > 0 && cross3 > 0);
	 bool isNegative = (cross1 < 0 && cross2 < 0 && cross3 < 0);

	// Si alguno de los anteriores es verdadero retornar verdadero
	return (isPositive || isNegative);
}