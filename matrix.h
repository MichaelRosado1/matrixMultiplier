#include <iostream>
#include <vector>

class Matrix {
	public:
		// default matrix of size 
		Matrix();
		// matrix with desired col and row 
		Matrix(int, int);

		Matrix operator+(const Matrix m2);



		void fill_defualt_matrix();
		void print_matrix();

		std::vector<std::vector<int> > matrix;	
		void addRow();
		void add_row_thread();
	private:
		int col_number, row_number;
};

