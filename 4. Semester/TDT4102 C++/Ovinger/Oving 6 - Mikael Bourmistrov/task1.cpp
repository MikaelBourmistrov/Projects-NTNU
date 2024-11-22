#include "std_lib_facilities.h"
#include <iostream>
#include "task1.h"  

void inputToFile(string filePath) {
    string input;
    ofstream outFile;

    outFile.open(filePath);
    cout << "Skriv inn linjer som du vi legge i " << filePath <<". Avslutt operasjonen med aa skrive inn 'quit'" << endl;

    do {
        cin >> input;
        if (input != "quit") {
            outFile << input << endl;
        }
    } while (input != "quit");
    outFile.close();
}

void addLineNumberToFile(string inputFilePath, string outputFilePath) {
    string line;
    int numberOfLines;
    ifstream innFile;
    ofstream outFile;
    vector<string> fileLines;

    innFile.open(inputFilePath);
    if (!innFile) error("Klarer ikke å åpne fil", inputFilePath);
    else {

        while (!innFile.eof()) {    //Om nødvendig, hjelper mye på oppgavene videre 
			getline(innFile, line); // ellers: int number_of_lines; while (getline(myfile, line)) ++number_of_lines;
			cout << line << endl;
			fileLines.push_back(line);
		}
		innFile.close();

        outFile.open(outputFilePath);
		if (!outFile) error("Klarer ikke å åpne fil", inputFilePath);
		else {
			for (int i = 0; i < fileLines.size(); ++i) {
				outFile << i + 1 << " " << fileLines[i] << endl;
			}
		}
    }
}