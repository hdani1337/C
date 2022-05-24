#include <iostream>

using namespace std;

class Matrix {
public:
	int **tomb;
	Matrix();
	Matrix(const Matrix &m);
	Matrix(int i1, int i2, int i3, int i4);
	~Matrix();
	Matrix operator+(const Matrix& masik) const;
	Matrix& operator=(const Matrix &masik);
	friend ostream& operator<<(ostream& stream, const Matrix& m);
};

Matrix::Matrix() {
	tomb = new int* [2];
	for (int i = 0; i < 2; i++) {
		tomb[i] = new int[2];
		for (int j = 0; j < 2; j++)
			tomb[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& m) {
	tomb = new int* [2];
	for (int i = 0; i < 2; i++) 
		tomb[i] = new int[2];
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			tomb[i][j] = m.tomb[i][j];
	}
}

Matrix::Matrix(int i1, int i2, int i3, int i4) {
	tomb = new int* [2];
	for (int i = 0; i < 2; i++)
		tomb[i] = new int[2];
	
	tomb[0][0] = i1;
	tomb[0][1] = i2;
	tomb[1][0] = i3;
	tomb[1][1] = i4;
}

Matrix::~Matrix() {
	for (int i = 0; i < 2; i++)
		delete[] tomb[i];
	delete[] tomb;
}

Matrix Matrix::operator+(const Matrix& masik) const {
	Matrix sum;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sum.tomb[i][j] = tomb[i][j] + masik.tomb[i][j];
	return sum;
}

Matrix& Matrix::operator=(const Matrix& masik) {
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++)
			tomb[i][j] = masik.tomb[i][j];
	return *this;
}

ostream& operator<<(ostream& stream, const Matrix& m) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			stream << "|" << m.tomb[i][j];		
		stream << "|" << endl;
	}
	return stream;
}

int main()
{
	Matrix m1(1,2,3,4);
	Matrix m2(5,2,5,3);
	Matrix m3(9,8,3,6);
	cout << "m1" << endl << m1 << endl;
	cout << "m2" << endl << m2 << endl;
	cout << "m1+m2" << endl << m1+m2 << endl;
	cout << "m3" << endl << m3 << endl;
	m3 = m1 + m2;
	cout << "m3 = m1 + m2" << endl << m3 << endl;
}