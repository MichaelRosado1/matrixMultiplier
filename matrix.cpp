#include "matrix.h"
#include <thread>
#include <vector>

Matrix::Matrix() {
	this->row_number = 2;
	this->col_number = 2;
	this->fill_defualt_matrix();
}

Matrix::Matrix(int col, int row) { 
	this->row_number = row;
	this->col_number = col;
}
void Matrix::addRow() {
	// std::vector<int> out_row;
	// for (int i = 0; m1.size(); i++) {
	// 	out_row.push_back(m1[i] + m2[i]);
	// }
	// out.matrix[rowNumber] = out_row;
	std::cout << "add row" << std::endl;
}

void Matrix::add_row_thread() {
	std::thread t = std::thread(&Matrix::addRow, this);
	t.join();
}

Matrix Matrix::operator+(const Matrix m2) {
	if ((this->col_number != m2.col_number) || (this->row_number != m2.row_number)) {
		//not possible to add
		return Matrix();
	}

	Matrix output(this->col_number, this->row_number);
	std::vector<std::thread> threadVector;	
	for (int i = 0; i < this->col_number; i++) {
		Matrix::add_row_thread();
	}

	for (auto& t : threadVector) {
		t.join();
	}
	
	return output;
}


void Matrix::fill_defualt_matrix() {
	// default 2x2 matrix
	for(int i = 0; i < this->col_number; i++) {
		std::vector<int> row;
		for(int j = 0; j < this->row_number; j++) {
			row.push_back(j);
		}
		this->matrix.push_back(row);
	} 
}


void Matrix::print_matrix() {
	for (int i = 0; i < this->col_number; i++) {
		std::cout << "row:" << i << " ["; 
		for (int j = 0; j < this->row_number; j++) {
			std::cout<< " " << this->matrix[i][j] << " ";
		}
		std::cout << "]\n";
	}
}



