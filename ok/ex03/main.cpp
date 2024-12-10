#include <iostream>
//#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

/*
const int MATRIX_WIDTH = 17;
const int MATRIX_HEIGHT = 12;

void initializeMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]);
void drawLine(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH], int x1, int y1, int x2, int y2, char fillChar);
void drawTriangleInMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]);
void printMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]);
*/

int main() {

	// Definición de los vértices del triángulo
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	// Definición de algunos puntos a probar
	Point insidePoint(5.0f, 5.0f);     // Punto dentro del triángulo
	Point outsidePoint(15.0f, 5.0f);   // Punto fuera del triángulo
	Point onEdgePoint(5.0f, 0.0f);     // Punto en el borde del triángulo
	Point vertexPoint(0.0f, 0.0f);     // Punto en uno de los vértices

	// Triangulo
	std::cout << "a =  0 .  0" << std::endl;
	std::cout << "b = 10 .  0" << std::endl;
	std::cout << "c =  5 . 10" << std::endl;

	// Pruebas para verificar si los puntos están dentro del triángulo
	std::cout << "Prueba 1: Punto dentro del triángulo" << std::endl;
	if (bsp(a, b, c, insidePoint)) {
		std::cout << "El punto (5.0, 5.0) está dentro del triángulo." << std::endl;
	} else {
		std::cout << "El punto (5.0, 5.0) está fuera del triángulo." << std::endl;
	}

	std::cout << "Prueba 2: Punto fuera del triángulo" << std::endl;
	if (bsp(a, b, c, outsidePoint)) {
		std::cout << "El punto (15.0, 5.0) está dentro del triángulo." << std::endl;
	} else {
		std::cout << "El punto (15.0, 5.0) está fuera del triángulo." << std::endl;
	}

	std::cout << "Prueba 3: Punto en el borde del triángulo" << std::endl;
	if (bsp(a, b, c, onEdgePoint)) {
		std::cout << "El punto (5.0, 0.0) está dentro del triángulo." << std::endl;
	} else {
		std::cout << "El punto (5.0, 0.0) está fuera del triángulo." << std::endl;
	}

	std::cout << "Prueba 4: Punto en uno de los vértices del triángulo" << std::endl;
	if (bsp(a, b, c, vertexPoint)) {
		std::cout << "El punto (0.0, 0.0) está dentro del triángulo." << std::endl;
	} else {
		std::cout << "El punto (0.0, 0.0) está fuera del triángulo." << std::endl;
	}

	/*
	// Dibujar triángulo de test
   char matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
	initializeMatrix(matrix);
	drawTriangleInMatrix(matrix);
	std::cout << std::endl;
	printMatrix(matrix);
	std::cout << std::endl; 
	*/

	return 0;
}

/*
// Función para inicializar la matriz con espacios vacíos
void initializeMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]) {
    for (int i = 0; i < MATRIX_HEIGHT; ++i) {
        for (int j = 0; j < MATRIX_WIDTH; ++j) {
            matrix[i][j] = ' ';  // Rellenar con espacios
        }
    }
}

// Función para dibujar líneas rectas entre dos puntos en la matriz
void drawLine(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH], int x1, int y1, int x2, int y2, char fillChar) {
    int dx = std::abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -std::abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        matrix[y1][x1] = fillChar;
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

// Función para dibujar la matriz según las especificaciones
void drawTriangleInMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]) {
    // Dibuja las líneas del triángulo
	drawLine(matrix, 0, 11, 10, 11, 'x');
	drawLine(matrix, 5, 1, 0, 11, 'x');
	drawLine(matrix, 5, 1, 10, 11, 'x');


    // Colocar los caracteres especiales
    matrix[11][0] = '4';  // (0, 0)
    matrix[6][5] = '1';   // (5, 5)
    matrix[6][15] = '2';  // (15, 5)
    matrix[11][5] = '3';  // (5, 0)
}

// Función para imprimir la matriz
void printMatrix(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]) {
    for (int i = 0; i < MATRIX_HEIGHT; ++i) {
        for (int j = 0; j < MATRIX_WIDTH; ++j) {
            // Imprimir los números en las posiciones con color brillante sobre fondo amarillo
            if (i == 11 && j == 0) {  // (0,0) -> '4'
                std::cout << "\033[1;91m\033[43m" << '4' << "\033[0m";  // Rojo brillante sobre fondo amarillo
            } else if (i == 6 && j == 5) {  // (5,5) -> '1'
                std::cout << "\033[1;92m\033[43m" << '1' << "\033[0m";  // Verde brillante sobre fondo amarillo
            } else if (i == 6 && j == 15) {  // (15,5) -> '2'
                std::cout << "\033[1;94m\033[43m" << '2' << "\033[0m";  // Azul brillante sobre fondo amarillo
            } else if (i == 11 && j == 5) {  // (5,0) -> '3'
                std::cout << "\033[1;95m\033[43m" << '3' << "\033[0m";  // Magenta brillante sobre fondo amarillo
            } else {
                // Imprimir el contenido normal de la matriz sin fondo amarillo
                std::cout << matrix[i][j] << " ";  // Sin fondo amarillo
            }
        }
        std::cout << std::endl;
    }
}
*/