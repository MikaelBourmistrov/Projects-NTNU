#include "fibonacci.h"

void fillInFibonacciNumbers(int* result, int length) {
    int low = 0, high = 1, sum;

    for (int i = 0; i < length; i++) {
        result[i] = low;

        sum = low + high;
        low = high;
        high = sum;
    }
}

void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) std::cout << arr[i] << std::endl;
}

void createFibonacci() {
    int lengthFibonacci;
    std::cout << "Hvor mange Fibonaccitall ønsker du å generere?: ";
    std::cin >> lengthFibonacci;

    int* fibonacciTable = new int[lengthFibonacci];            //har kalt new, så må delete senere
    fillInFibonacciNumbers(fibonacciTable, lengthFibonacci);

    printArray(fibonacciTable, lengthFibonacci);

    delete[] fibonacciTable;
    fibonacciTable = nullptr;
}