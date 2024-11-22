/////////////////////////////////////////////////////// Øving 2 Mikael Bourmistrov ///////////////////////////////////////////////////////
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

////////////////////////////////////////////////////// Funksjoner //////////////////////////////////////////////////////

////////////////////////// [1] Menysystem, Funksjoner og «Input/Output» (30%) //////////////////////////
////////// oppgave a) //////////
void add() {                            
    int x;                               
    int y;                               

    cout << "Skriv inn to heltall: ";
    cin >> x;
    cin >> y;
    cout << x << " + " << y << " = " << x + y << endl; 
}

void add_multi() {  
    int n;
    int x;
    int sum = 0;

    cout << "Hvor mange heltall vil du summere?: ";                 
    cin >> n;

    if(n < 2){
        cout << "Tast inn riktig tall! (int, og ikke mindre enn 2)" << endl;
        add_multi();
        return;
    }

    for(int i = 0; i < n; ++i) {
        cout << "Skriv inn det " << i+1 << ". heltallet: ";
        cin >> x;
        sum += x;
    }
    cout << "Summen av de " << n << " heltallene dine er: " << sum << endl;
}

void konv_nok_eur() {
    int nok;                               

    cout << "Skriv inn ett heltall av kroner du vil ha i euro: ";   
    cin >> nok;
    cout << nok << "kr er " << nok * 0.093 << " euro."  << endl; 
}

////////// oppgave b) //////////
void inputAndPrintInteger() {
    int tall;

    cout << "Skriv inn et tall: ";
    cin >> tall;
    cout << "Du skrev:" << tall << endl;
}

////////// oppgave c) //////////
int inputInteger() {
    int number;

    cout << "Skriv inn et tall: "; 
    cin >> number;
    return number;
}

////////// oppgave d) //////////
void inputIntegersAndPrintSum() {        
    int num_1 = inputInteger();                     
    int num_2 = inputInteger();                              
    cout << "Summen av tallene: " << num_1 + num_2 << endl;
}

////////// oppgave e) //////////
// inputInteger virket som en bedre egnet funskjon siden den faktisk returenerer en verdi, dermed kan jeg definere
// noen variabler med verider med egne nav og summere dem på en linje med kode.

////////// oppgave f) //////////
int isOdd(int x) {
    if (x % 2 == 1) {
        return 1;
    }
    else {
        return 0;
    } 
}

////////// oppgave g) //////////
void printHumanReadableTime(int sek) {
    int days = sek / 86400;
    int hours = (sek % 86400) / 3600;
    int mins = (sek % 3600) / 60;
    int seconds = (sek % 60);
    cout << "Days: " << days << " Hours: " << hours << " Minuttes: " << mins << " Seconds: " << seconds << endl;
}


////////////////////////// [2] Løkker (10%) //////////////////////////
////////// oppgave a) //////////
void add_multi_2() { 
    int n, x, sum = 0;

    cout << "Hvor mange heltall vil du summere?: ";                 
    cin >> n;

    if(n < 2) {
        cout << "Tast inn riktig tall! (int, og ikke mindre enn 2)" << endl;
        add_multi();
        return;
    }

    for(int i = 0; i < n; ++i) {
        cout << "Skriv inn det " << i+1 << ". heltallet: ";
        cin >> x;
        sum += x;
    }
    cout << "Summen av de " << n << " heltallene dine er: " << sum << endl;
}

////////// oppgave b) //////////
void sum_until_0() {
    int number, sum = 0;
    do {
        cout << "Skriv inn ett tall (0 for avslutte) \n\t:" ;
        cin >> number;
        sum += number;
    } while (number != 0);
    cout << "Summen av tallene dine: " << sum << endl;
}

////////// oppgave c) //////////
// For oppgave a er det bedre med en for løkke siden vi kjenner til hvor mange ganger den skal kjøre,
// altså antall ganger personen ga som inputt. På oppgave b er det while som er bedre egnet, siden
// vi er ussikre på hvor mange ganger brukeren kommer til å taste inn tall før 0.

////////// oppgave d) //////////
double inputDouble() {
    double number;

    cout << "Skriv inn et tall: ";
    while((!(cin >> number)) or (number < 0)) {
        cout << "Error: Skriv inn et tall!: " << endl; 
    }
    return number;
}

////////// oppgave e) //////////
double convert_nok_to_euro() {
    double nok = inputDouble();
    return nok / 9.75;
}

////////// oppgave f) //////////
// Det er best å bruke inputDouble siden man kan da definere ett nytt tall som man kan endre på, og senere skrive ut
// og ikke gjøre det tidligere. I tilleg vil jeg at jeg kan definere verdien til euroen gjennom funskjonen, så derfor har jeg ikke void.

////////// oppgave g) //////////
void user_multi_table() {
    int height;
    int width;

    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;

    for (int h = 1; h < height + 1; ++h) {
        for (int w = 1; w < width + 1; ++w) {
            cout << w*h << setw(4);
        }
        cout << endl << setw(0);
    }
        
}


////////////////////////// [3] Bruk av funksjoner i funksjoner, og røtter (20%) //////////////////////////
////////// oppgave a) //////////
double discriminant(double a, double b, double c) {
    return pow(b, 2) - (4*a*c);
}

////////// oppgave b) //////////
void printRealRoots(double a, double b, double c) {
    double inside = discriminant(a, b, c);
    if(inside > 0) {
        cout << "Your roots are: ";
        cout << ((-b + (sqrt(inside)))/2*a) << " and " << ((-b - (sqrt(inside)))/2*a) << endl;
    }
    else if(inside == 0) {
        cout << "Your root is: ";
        cout << -b/(2*a) << endl;
    }
    else {
        cout << "Det finnes ingen reele losninger." << endl;
    }

}

////////// oppgave c) //////////
void solveQuadraticEquation() {
    double a, b, c;
    cout << "Skriv inn a: ";
    cin >> a;
    cout << "Skriv inn b: ";
    cin >> b;
    cout << "Skriv inn c: ";
    cin >> c;
    printRealRoots(a, b, c);
}

////////////////////////// [5] Renter med bruk av løkker (15%) //////////////////////////
////////// oppgave a) //////////
vector<double> calculateBalance(double innskud, int rente, int aar) {
    vector<double> year_vector;

    for (int i = 0; i < aar + 1; i++) {
        year_vector.push_back(innskud * pow((1 + static_cast<double>(rente)/100), i));
    }

    return year_vector;
}

////////// oppgave b) //////////
void printBalance(vector<double> aar_vektor) {
    cout << "Aar" << setw(10) << "Saldo" << endl;

    for (int i = 0; i < static_cast<int>(aar_vektor.size()); i++) {
        cout << i << setw(12) << aar_vektor[i] << endl;
    }
}

////////// oppgave c) //////////
// Denne vanlige feilen skyldes av at brukeren prøver å printe ut ett objekt (samling av verdier og funskjoner, altså selve vektoren), 
// som programmet rett og slett ikke forstår hvordan den skal tolke dette. 

////////////////////////////////////////////////////// Mainfunksjon //////////////////////////////////////////////////////

int main() {
    ////////////////////////// [1] Menysystem, Funksjoner og «Input/Output» (30%) //////////////////////////
    ////////// oppgave a) //////////
    while(true) {
        cout << "Velg funksjon:" << endl
             << "0) Avslutt" << endl
             << "1) Summer to tall" << endl
             << "2) Summer flere tall" << endl
             << "3) Konverter NOK til EURO." << endl
             << "Angi valg (0-3): ";

        char input;
        cin >> input;

        if(input == '0') {
            break;
        }
        else if(input == '1') {
            add();
        }
        else if(input == '2') {
            add_multi();
        }
        else if(input == '3') {
            konv_nok_eur();
        }
        else {
            cout << "Oppgi en korrekt verdi!" << endl;
        }

    }
    
    ////////// oppgave b) //////////
    inputAndPrintInteger();

    ////////// oppgave c) //////////
    int number = inputInteger();
    cout << "Du skrev: " << number << endl;

    ////////// oppgave d) //////////
    inputIntegersAndPrintSum();

    ////////// oppgave f) //////////
    for (int i = 0; i < 16; ++i) 
        cout << (isOdd(i) ? "true" : "false") << endl; 

    ////////// oppgave g) //////////
    printHumanReadableTime(186320);


    ////////////////////////// [2] Løkker (10%) //////////////////////////
    ////////// oppgave a) //////////
    add_multi_2();

    ////////// oppgave b) //////////
    sum_until_0();

    ////////// oppgave d) //////////
    inputDouble();

    ////////// oppgave e) //////////
    double pengeverdi = convert_nok_to_euro();
    cout << "Tallet du skrev inn er verdt " << setprecision(2) << fixed << pengeverdi << " i euro" << endl;

    ////////// oppgave g) //////////
    user_multi_table();


    ////////////////////////// [3] Bruk av funksjoner i funksjoner, og røtter (20%) //////////////////////////
    ////////// oppgave a) //////////
    cout << discriminant(1, 3, 2) << endl;

    ////////// oppgave d) //////////
    solveQuadraticEquation();


    ////////////////////////// [4] Grafikk - Pythagoras’ læresetning (25%) //////////////////////////
    ////////// oppgave b), c) og d) //////////
    Point point1{300, 300}, point2{300, 600}, point3{500, 600}; //For trekanten
    Point point_s_11{0, 600}, point_s_12{0, 300};               //
    Point point_s_21{500, 800}, point_s_22{300, 800};           //For firkantene
    Point point_s_31{600, 100}, point_s_32{800, 400};           //
    
    AnimationWindow win{100, 100, 1200, 900, "Pythagoras"};
    win.draw_triangle(point1, point2, point3, Color::black);

    win.draw_quad(point1, point2, point_s_11, point_s_12, Color::green);
    win.draw_quad(point2, point3, point_s_21, point_s_22, Color::red);
    win.draw_quad(point3, point1, point_s_31, point_s_32, Color::blue);

    win.wait_for_close();

    ////////////////////////// [5] Renter med bruk av løkker (15%) //////////////////////////
    ////////// oppgave a) og b) //////////
    printBalance(calculateBalance(5000, 3, 10));

    ////////// oppgave d) //////////
    //vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (int i = 0; i <= v.size(); i++) {
    //    cout << v.at(i) << endl;
    //}

    // Feilen ligger i at for loopen har brukeren satt i <= v.size(), så prøver han å 
    // hente element fra en del av arrayen som ikke eksister, altså element 10.

    return 0;
}
