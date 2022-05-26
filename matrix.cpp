#include "matrix.h"

Matrix::Matrix() {
	this->row_number = 2;
	this->col_number = 2;
	this->fill_defualt_matrix();
}

void Matrix::fill_defualt_matrix() {
	/*
	{}

	*/
	for(int i = 0; i < this->col_number; i++) {
		std::vector<int> row;
		for(int j = 0; j < this->row_number; j++) {
			row.push_back(0);
		}
		this->matrix.push_back(row);
	} 
}


void Matrix::print_matrix() {
	for (int i = 0; i < this->col_number; i++) {
		std::cout << "row: " << i << std::endl;
		for (int j = 0; j < this->row_number; j++) {
			std::cout << "value at [" << i << "][" << j << "]: " << this->matrix[i][j]<< std::endl;
		}
	}
}