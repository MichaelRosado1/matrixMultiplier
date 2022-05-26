#include <iostream>
#include <vector>

class Matrix {
	public:
		// default matrix of size 
		Matrix();
		// matrix with desired col and row 
		Matrix(int, int);
		void fill_defualt_matrix();
		void print_matrix();
	private:
		int col_number, row_number;
		std::vector<std::vector<int> > matrix;	
};