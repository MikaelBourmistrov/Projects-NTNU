#include "std_lib_facilities.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
    return capitalsMap.at(country);            // feilmelding: no viable overloaded operator[]
}

int main() {
//////////////////////////////////// Oppgave 1 ////////////////////////////////////
    inputToFile("JustRandomFile.txt");
    
    addLineNumberToFile("BreakMyStrideLyrics.txt", "TestFileWithNumbers.txt");

//////////////////////////////////// Oppgave 2 ////////////////////////////////////
    countCharInText("grunnlov.txt");

    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap) {
        cout << getCapital(elem.first) << std::endl;
    }

//////////////////////////////////// Oppgave 3 ////////////////////////////////////
    CourseCatalog codeAndName = CourseCatalog();

	//codeAndName.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	//codeAndName.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	//codeAndName.addCourse("TMA4100", "Matematikk 1");
    //codeAndName.addCourse("TDT4102", "C++"); //ingenting sjer når insert() brukes og dette skyldes av hvordan den fungerer, vil bare legge til nye verdier og ikke erstatte. Mens [] opperatoren er mye som å se på ett listeelement, vi setter den = noe, så da kan vi "replace". 

    //codeAndName.saveCourses("CoursesWithNames.txt", codeAndName);
    //cout << codeAndName << "--------------";
    codeAndName.loadCourses("CoursesWithNames2.txt", codeAndName);
    cout << codeAndName;

    std::filesystem::path temperatureFile{"temperatures.txt"};
    std::ifstream temp_file{temperatureFile};
    Temps t;
    temp_file >> t;
    cout << "t.max: " << t.max << " t.min: " << t.min << endl;     

    vector<Temps> temps = readTemps("temperatures.txt");  
    tempStats(temps);

    return 0;
} 