// A matrix algebra class
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <utility>
#include <iostream>

class Matrix
{
public:
    //Constructors
    Matrix();
    Matrix(const Matrix &other);
    Matrix(int m, int n);

    //get the matrix dimensions
    std::pair<int, int> dim() const;

    //operators
    std::vector<double> & operator[](int index);   //returns a row vector reference
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(double s) const;   //scalar multiplication A * s
private:
    std::vector<std::vector<double>> elements;  //matrix elements
};

//external operators
double operator*(double s, const Matrix &m);  //scalar multiplcation s * m
std::ostream & operator<<(std::ostream &os, const Matrix &m);   //extraction operator
std::istream & operator>>(std::istream &is, const Matrix &m);    //insertion operator
#endif

