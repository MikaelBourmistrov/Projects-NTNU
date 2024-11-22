#include "std_lib_facilities.h"
#include "test.h"
#include "cannonball.h"

//////////////////////////////// [3] Verifiser at funksjonene fungerer (15%) ////////////////////////////////
///////////////// Oppgave a) /////////////////
void checkValues(double initPosX, double initPosY, double initVelX, double initVelY) {
    double t[4] = {0, 2.5, 5, 7.5};
    for (int j = 0; j < 5; j++) {
        cout << ((j == 0)?"":"");
        cout << ((j == 1)?"Vel X":"");
        cout << ((j == 2)?"Vel Y":"");
        cout << ((j == 3)?"Pos X":"");
        cout << ((j == 4)?"Pos Y":"");
        for (int i = 0; i < sizeof(t)/sizeof(double); i++) {
            switch(j) {    
                case 0: cout << "\tT = " << t[i]; break;
                case 1: cout << "\t" << initVelX; break;
                case 2: cout << "\t" << velY(initVelY, t[i]); break;
                case 3: cout << "\t" << posX(initPosX, initVelX, t[i]); break;
                case 4: cout << "\t" << posY(initPosY, initVelY, t[i]); break;
            }
        }
    cout << endl; 
    }
}

///////////////// Oppgave b) /////////////////
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) <= maxError) {
        cout << name << " is valid." << endl;
    }
    else {
        cout << name << " is not valid, expected " << toOperand << ", got " << compareOperand << endl;
    }
}


