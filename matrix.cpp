#include "matrix.h"
#include <fstream>
#include <thread>
#include <vector>
#include <string>


Matrix::Matrix(int col, int row) {
	this->row_number = row;
	this->col_number = col;
	this->fill_defualt_matrix(this->col_number, this->row_number);	
}

Matrix::Matrix(int col, int row, std::string filepath) { 
	this->row_number = row;
	this->col_number = col;
	// building empty vector
	this->mat.resize(this->row_number);
	for (auto& m: this->mat)
		m.resize(this->col_number);

	this->load_matrix(filepath);

}

void Matrix::load_matrix(std::string filepath) {
	std::ifstream file(filepath);

	if (!file) {
		std::cout << "error opening matrix file. " << std::endl;
		return;
	}	
	for (auto& outer: this->mat) {
		for (auto& inner: outer) {
			file >> inner;
		}
	}
}

void Matrix::addRow(Matrix m1, Matrix m2, int row) {

}

std::thread Matrix::add_row_thread(Matrix m1, Matrix m2, int row) {
	std::thread t = std::thread(&Matrix::addRow, this, m1, m2, row);
	return t;
}

Matrix Matrix::operator+(const Matrix m2) {
	if ((this->col_number != m2.col_number) || (this->row_number != m2.row_number)) {
		//not possible to add
		return Matrix();
	}

	Matrix output(this->col_number, this->row_number);
	std::vector<std::thread> threadVector;	
	for (int i = 0; i < this->col_number; i++) {
		threadVector.push_back(Matrix::add_row_thread(*this, m2, i));
	}

	for (auto& t : threadVector) {
		t.join();
	}
	
	return output;
}


void Matrix::fill_defualt_matrix(int col, int row) {
	// default 2x2 matrix
	for(int i = 0; i < col; i++) {
		std::vector<int> matrixrow;
		for(int j = 0; j < row; j++) {
			matrixrow.push_back(j);
		}
		this->matrix.push_back(matrixrow);
	} 
}


void Matrix::print_matrix() {
	for (auto& r: this->mat) {
		std::cout << "{";
		for (auto& c: r) {
			std::cout << c << ", ";
		}
		std::cout << "} \n";
	}
}
