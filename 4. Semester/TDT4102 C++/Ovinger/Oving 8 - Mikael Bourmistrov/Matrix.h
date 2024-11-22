#pragma once
#include <iostream> 
#include <iomanip>
#include <utility>

class Matrix {
    private:
        int m_rows, m_cols;
        double** matrix;             // en pointer (kan også ses på som en vektor) som holder rows, der hver row inneholder en cols pointer

    public:
        Matrix();                    // Construktorer og destruktor, dette er standardopperatoren
        Matrix(int rows, int cols);
        explicit Matrix(int nRows);

        Matrix(const Matrix & other);

        ~Matrix(); 

    public:                          // Funksjoner
        double get(int row, int col) const;

        void set(int row, int col, double value);

        int getRows() const;

        int getColumns() const;

    public:                         // Opperatorer
        double* operator [] (const int& pos) const;

        Matrix& operator = (Matrix rhs);

        Matrix& operator += (const Matrix& rhs);

};

Matrix operator + (Matrix lhs, const Matrix & rhs);

std::ostream& operator << (std::ostream& outstream, const Matrix& m);

