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
    virtual std::pair<int, int> dim() const;

    //operators
    virtual std::vector<double> & operator[](int index);   //returns a row vector reference
    virtual const std::vector<double> &operator[](int index) const;  //read only version
    virtual Matrix operator+(const Matrix &rhs) const;
    virtual Matrix operator*(double s) const;   //scalar multiplication A * s
private:
    std::vector<std::vector<double>> elements;  //matrix elements
};

//external operators
Matrix operator*(double s, const Matrix &m);  //scalar multiplcation s * m
std::ostream & operator<<(std::ostream &os, const Matrix &m);   //insertion operator
std::istream & operator>>(std::istream &is, Matrix &m);    //extraction operator
#endif

