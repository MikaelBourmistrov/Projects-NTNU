#include "std_lib_facilities.h"
#include "task4.h"
#include "task1.h"

istream& operator>>(istream& is, Temps& t) {
    double inMax, inMin;

	is >> t.max >> t.min;

	return is;
}

vector<Temps> readTemps(string filePath) {
	ifstream inFile;
	Temps t;
	string line;
	vector<Temps> temps;

	inFile.open(filePath);
	while (getline(inFile, line)) {
		istringstream ss(line);
		ss >> t;
		temps.push_back(t);
	}
	inFile.close();

	return temps;
}

void tempStats(vector<Temps> temps) {
	double maxTemp = 0, minTemp = 0;
	int maxTempDay, minTempDay;

	for (int i = 0; i < (temps.size()); ++i) {
		if (maxTemp < temps[i].max) {
			maxTemp = temps[i].max;
			maxTempDay = i+1;
		}

		if (minTemp > temps[i].min) {
			minTemp = temps[i].min;
			minTempDay = i+1;
		}
	}

	cout << "Den storste temperaturen var: "<< maxTemp << ", paa den " << maxTempDay <<". dagen." << endl;
	cout << "Den minste temperaturen var: "<< minTemp << ", paa den " << minTempDay <<". dagen.";
}
