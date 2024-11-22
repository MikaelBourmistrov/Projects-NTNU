/////////////////////// [2] Oversett fra Python til C++ (90%) ///////////////////////

#include "std_lib_facilities.h"


/////////////////////// Funksjoner ///////////////////////
///// Oppgave a) /////
double maxOfTwo(double a, double b) {
    if (a > b){
        cout << "A is greater than B" << endl;
        return a;} 
    else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

///// Oppgave c) /////
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:" << endl;

    for (int x = 1; x < n+1; ++x) {
        cout << x << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }  

    cout << "------" << endl;
    return b;   
}

///// Oppgave d) /////
int squareNumberSum(int n) {
    int totalSum = 0;

    for (int i = 1; i < n+1; ++i) {
        totalSum += i * i;
        cout << i * i << endl;
    }

    cout << totalSum << endl;
    return totalSum;
}

//// Oppgave e) /////
void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
}

///// Oppgave f) /////
bool isPrime(int n) {
    for (int j = 2; j < n; ++j) {
        if (n % j == 0) {
            return 0;
        }
    }

    return 1;
}

///// Oppgave g) /////
void naivePrimeNumberSearch(int n) {
    for (int number = 2; number < n; ++number) {
        if (isPrime(number) == 1) {
            cout << number << " is a prime" << endl;
        }
    }
}
// Kommentar: En void funskjon kan ikke returnere VERDIER, men kan returenere andre ting.
//            For eksempel en annen funksjon. Dessuten er det mulig å "cout-e" returverdien istedenfor å spørre for en retur av den.

///// Oppgave h) /////
int findGreatestDivisor(int n) {
    for (int divisor = n-1; divisor > 0; divisor += -1) {
        if (n % divisor == 0) {
            return divisor;
        }
    }
}


/////////////////////// Mainfunksjon ///////////////////////

int main() {
///// Oppgave b) /////
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 6) << endl << endl;

///// Oppgave c) /////
    cout << "Oppgave c)" << endl;
    cout << fibonacci(5) << endl << endl;

///// Oppgave d) /////
    cout << "Oppgave d)" << endl;
    cout << squareNumberSum(5) << endl << endl;

//// Oppgave e) /////
    cout << "Oppgave e)" << endl;
    triangleNumbersBelow(10);

///// Oppgave f) og g) /////
    cout << endl << "Oppgave f) og g)" << endl;
    naivePrimeNumberSearch(14);

///// Oppgave h) ///// 
    cout << endl << "Oppgave h)" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;
   
}
