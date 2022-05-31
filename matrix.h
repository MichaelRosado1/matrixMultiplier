#include <iostream>
#include <vector>

class Matrix {
	public:
		// default matrix of size 
		// matrix with desired col and row 
		Matrix(int col = 2, int row = 2);

		Matrix(int, int, std::string);

		void load_matrix(std::string);

		Matrix operator+(const Matrix m2);



		void fill_defualt_matrix(int, int);
		void print_matrix();

		std::vector<std::vector<int> > matrix;	
		void addRow(Matrix, Matrix, int);
		std::thread add_row_thread(Matrix, Matrix, int);
	private:
		int col_number, row_number;
		std::vector<std::vector<int>> mat;
};

