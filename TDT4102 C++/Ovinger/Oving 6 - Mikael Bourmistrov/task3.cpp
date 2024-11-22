#include "std_lib_facilities.h"
#include "task3.h"

CourseCatalog::CourseCatalog() {}

void CourseCatalog::addCourse(string code, string name) {
    //codeAndName.insert({code, name});
    codeAndName[code] = name;
}

void CourseCatalog::removeCourse(string code) {
    codeAndName.erase(code);
}

string CourseCatalog::getCourse(string code) {
    return codeAndName.at(code);
}

ostream& operator << (ostream& os, const CourseCatalog& c) {
    string courses;

    for (const auto cc : c.codeAndName) {            // const auto vil gjøre at cc (course content) er "av typen" mapet vorres altså codeAndName altså pair<const string, const string>
        os << cc.first + ':' + cc.second;
    }
    return os;
}

void CourseCatalog::saveCourses(string filePath, CourseCatalog codeAndName) { //må være mulig å ikke ta inn codeAndName,men lar meg ikke ellers.
    ofstream outFile;

    outFile.open(filePath);
    outFile << codeAndName;
    outFile.close();
}

void CourseCatalog::loadCourses(string filePath, CourseCatalog codeAndName) {
    ifstream inFile;
    string line;
    string simplified;
    vector<string> codeNameVector;

    inFile.open("CoursesWithNames2.txt");
    while (getline(inFile, line)) simplified += line + ":";
    stringstream ss(simplified);
    while (getline(ss, line, ':')) codeNameVector.push_back(line);
    inFile.close();

    for (int i = 0; i < codeNameVector.size(); i += 2) {
        codeAndName.addCourse(codeNameVector[i], codeNameVector[i+1]);
        //cout << codeNameVector[i] << ":" << codeNameVector[i+1] << '\n';
    }
}