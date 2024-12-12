#include "Point.hpp"
#include "Fixed.hpp"

// Constructores

// Default
Point::Point() : x(0), y(0) {}

// Parámetro
Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val)) {}

// Copia
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Sobrecarga el operador de asignación
Point& Point::operator=(const Point& /*other*/) {
    return *this;
}

// Descructor
Point::~Point() {}

// Getters
Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}