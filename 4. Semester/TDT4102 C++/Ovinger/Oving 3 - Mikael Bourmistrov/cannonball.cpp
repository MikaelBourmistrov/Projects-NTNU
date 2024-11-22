#include "std_lib_facilities.h"
#include "cannonball.h"

//////////////////////////////// [2] Implementer funksjoner (15%) ////////////////////////////////
double acclY() {return -9.81;}

double velY(double initVelocity, double time) {
    double velocity_Y = initVelocity + (acclY() * time);
    return velocity_Y;
}

double velX(double initVelocity, double time) {
    double velocity_X = initVelocity;
    return velocity_X;
}

double posX(double initPosition, double initVelocity, double time) {
    double postition_X = initPosition + (initVelocity * time);
    return postition_X;
}

double posY(double initPosition, double initVelocity, double time) {
    double postition_Y = initPosition + (initVelocity * time) + ((acclY() * pow(time,2)) / 2);
    return postition_Y;
}

void printTime(int time) {
    int hours = (time / 3600);
    int minutes = (time % 3600) / 60;
    int seconds = time % 60;
    if (hours > 0) {cout << hours << " Time" << ((hours > 1)?"r, ":", ");}
    if (minutes > 0) {cout << minutes << " Minutt" << ((minutes > 1)?"er, ":", ");}
    cout << seconds << " Sekund" << ((seconds > 1)?"er":"") << endl;
}

double flightTime(double initVelocity) {
    return -2*(initVelocity/acclY());
}