#include "fibonacci.h"
#include "Matrix.h"
#include "Dummy.h"

int main() {
    int n = 5;
    Matrix nullMatrix(n, n+1);
    Matrix identity(n);

    std::cout << "Antall rows: " << nullMatrix.getRows() << ", og antall columns: " << nullMatrix.getColumns() << "\n";
    nullMatrix.set(2, 3, 3.14);
    std::cout << nullMatrix.get(2, 3) << "\n";

    std::cout << nullMatrix << "\n";
    std::cout << identity;
    std::cout << identity[1][1] << "\n";

    dummyTest();   // lar meg ikke runne det når jeg ikke har en copy consttruct, og overlaset overlaster = opperatoren, men vet det vil gi det jeg sa i a, og vil krsæje til slutt siden destruktoren prøver å slette minne som ikke er allokert til oss lengre, dette er ulovlig og skal egentlig krasje programmet.

    Matrix NCopy(nullMatrix);
    Matrix NCopyCopy = NCopy;
    std::cout << NCopy << "\n" << NCopyCopy << "\n";

    Matrix A(2), B(2), C(2);

    A.set(0, 0, 1.0), A.set(0, 1, 2.0), A.set(1, 0, 3.0), A.set(1, 1, 4.0);
    B.set(0, 0, 4.0), B.set(0, 1, 3.0), B.set(1, 0, 2.0), B.set(1, 1, 1.0);
    C.set(0, 0, 1.0), C.set(0, 1, 3.0), C.set(1, 0, 1.5), C.set(1, 1, 2.0);

    A += B + C;

    std::cout << "A: \n" << A << "\n";
    std::cout << "B: \n" << B << "\n";
    std::cout << "C: \n" << C << "\n";  

    return 0;
}

