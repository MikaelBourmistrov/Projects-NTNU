//////////////////////////////// [1] Funksjonsdeklarasjoner (10%) ////////////////////////////////
#pragma once
double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(int time);

double flightTime(double initVelocity);