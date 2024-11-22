#include "Car.h"

bool Car::hasFreeSeats() const {
    return (freeSeats != 0);
}

void Car::reserveFreeSeat() {
    freeSeats--;
}

Car::Car(unsigned int numFreeSeats): freeSeats(numFreeSeats) {}