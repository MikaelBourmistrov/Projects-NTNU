#include "Matrix.h"

Matrix::Matrix(): m_rows(0), m_cols(0), matrix(new double*[0]) {}  // default operator, ikke gyldig matrise

Matrix::Matrix(const int nRows, const int nColumns): m_rows(nRows), m_cols(nColumns), matrix(new double*[nColumns]) 
{
    for (int i = 0; i < nRows; i++) {
        matrix[i] = new double[nColumns];                          //kaller new så må huske å kalle delete seinere 
        for (int j = 0; j < nColumns; j++) { matrix[i][j] = 0; }   //skaper en nullmatrise
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows)                   // husk denne linjen skaper en pointer med pointers kalt matrix (som inneholder 0er).
{
	for (int i = 0; i < nRows; i++) {
		matrix[i][i] = 1;
	}
}

Matrix::~Matrix() {      // Det her e en destruktor Jokke, den skrives slik så man får alle pointers sletta
    for (int i = 0; i<m_rows; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}

double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

double* Matrix::operator[](const int& pos) const {
    return matrix[pos];
}

int Matrix::getRows() const {
    return m_rows;                    //husk m_ står for memnber i mitt system, så det returenerer størreksen på den
}

int Matrix::getColumns() const {
    return m_cols;
}

std::ostream& operator << (std::ostream& outstream, const Matrix& m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++) {
            outstream << ' ' << std::setw(2) << m.get(i, j); 
        }
        outstream << std::endl;
    }
    return outstream;
}

////////////////////////// 4 og 5 //////////////////////////

Matrix::Matrix(const Matrix& other): m_rows(other.m_rows), m_cols(other.m_cols), matrix(new double*[other.m_cols]) 
{
    for (int i = 0; i < other.m_rows; i++) {
        matrix[i] = new double[other.m_cols];                          //kaller new så må huske å kalle delete seinere 
        for (int j = 0; j < other.m_cols; j++) { matrix[i][j] = other.matrix[i][j]; }   //skaper en nullmatrise
    }
}

Matrix& Matrix::operator = (Matrix rhs) {
    std::swap(matrix, rhs.matrix);
    return *this;
}

Matrix& Matrix::operator += (const Matrix& rhs) {
	if (m_rows == rhs.m_rows && m_cols == rhs.m_cols) { // veldig rotete, burde egentlig kanskje skrive this->m_rows, for å gjøre det mer tydelig. Er det en forskjell?
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++) {
				matrix[i][j] += rhs.get(i, j);
			}
		}
		return *this;
	}

	matrix = nullptr;
    return *this;
}

Matrix operator + (Matrix lhs, const Matrix & rhs) {   // så første argument er hva venstre side er, men dette trengs ikke ved inne i klassen. Venstre ikke ref siden vil ikke endre på verdien til det tatt inn, dette er en kopi i stdet (dette kan ses på å være ueffektivt).
	lhs += rhs; 
	return lhs;
}
