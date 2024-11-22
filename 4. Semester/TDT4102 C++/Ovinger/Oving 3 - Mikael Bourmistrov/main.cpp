#include "std_lib_facilities.h"
#include "cannonball.h"
#include "test.h"

int main() {
//////////////////////////////// [3] Verifiser at funksjonene fungerer (15%) ////////////////////////////////
///////////////// Oppgave a) /////////////////
    double initPosX = 0, initPosY = 0;
    double initVelX = 50;
    double initVelY = 25;

    checkValues(initPosX, initPosY, initVelX, initVelY); // se test.h, tester for t = 0, 2.5, 5, 7.5
    
///////////////// Oppgave c) /////////////////
    double maxError = 0.0001;

    testDeviation(posX(0.0,50.0,5.0), 250, maxError, "posX(0.0,50.0,5.0)");
    testDeviation(posY(0.0,25.0,5.0), 2.375, maxError, "posY(0.0,50.0,5.0)");
    testDeviation(velY(25, 2.5), 0.475, maxError, "velY(25, 2.5)");
    testDeviation(acclY(), 9.81, maxError, "acclY(");
    return 0;
}
