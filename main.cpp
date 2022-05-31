#include <iostream>
#include "matrix.h"

int main() {
	Matrix m1 = Matrix(2,2, "./matrices/m1.txt");

	m1.print_matrix();	
}
