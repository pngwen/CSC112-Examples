#include "matrix.h"

using namespace std;

//contructors
Matrix::Matrix()
{
    //do nothing
}


//Copy constructor
Matrix::Matrix(const Matrix &other) : elements(other.elements)
{
    //do nothing
}


//Define with dimensions
Matrix::Matrix(int m, int n) : elements(m, vector<double>(n))
{
    //do nothing
}



//return the dimensions
pair<int, int> Matrix::dim() const
{
    pair<int, int> d;

    //get the number of rows
    d.first = elements.size();

    if(d.first == 0) {
	//handle an empty matrix
	d.second = 0;
    } else {
	//get the number of columns
	d.second = elements[0].size();
    }

    return d;
}


//return a row vector
vector<double>& Matrix::operator[](int index)
{
    return elements[index];
}


const std::vector<double> & Matrix::operator[](int index) const
{
    return elements[index];
}


//Add two matrices
Matrix Matrix::operator+(const Matrix &rhs) const
{
    //make a new matrix with the same dimensions as the present one
    pair<int, int> d = dim();
    Matrix result(d.first, d.second);

    //add the matrices
    for(int i=0; i<d.first; i++) { //row loop
	for(int j=0; j<d.second; j++) { //col loop
	    result[i][j] = (*this)[i][j] + rhs[i][j];
	}
    }

    return result;
	
}


//scalar multiplication
Matrix Matrix::operator*(double s) const
{
     //make a new matrix with the same dimensions as the present one
    pair<int, int> d = dim();
    Matrix result(d.first, d.second);
    
    for(int i=0; i<d.first; i++) { //row loop
	for(int j=0; j<d.second; j++) { //col loop
	    result[i][j] = (*this)[i][j] * s;
	}
    }

    return result;
}


//scalar multiplication (external)
Matrix operator*(double s, const Matrix &m)
{
    return m * s;
}


//insertion operator
ostream &operator<<(ostream &os, const Matrix &m)
{
    pair<int, int> d = m.dim();

    for(int i=0; i<d.first; i++) { //row loop
	for(int j=0; j<d.second; j++) {
	    os << m[i][j] << "\t";
	}
	os << endl;
    }

    return os;
}


//extraction operator
istream &operator>>(istream &is, Matrix &m)
{
    pair<int, int> d = m.dim();

    for(int i=0; i<d.first; i++) { //row loop
	for(int j=0; j<d.second; j++) {
	    is >> m[i][j];
	}
    }

    return is;
}
