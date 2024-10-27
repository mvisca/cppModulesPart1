#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

    private:
        const Fixed x;
        const Fixed y;

    public:
        // Constructores

        // Default
        Point();
        // Parámetro
        Point(const float x, const float y);
        // Copia
        Point(const Point& other);

        // Sobrecarga el operador de asignación
        Point& operator=(const Point& other);

        // Descructor
        ~Point();

        // Getters
        Fixed getX() const;
        Fixed getY() const;
};

// bsp devuelve true si 'point' está dentro el triángulo 'a-b-c'
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif