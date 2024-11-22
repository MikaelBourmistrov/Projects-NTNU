#pragma once
#include "std_lib_facilities.h"

struct Temps {
	double max, min;
};

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemps(string filePath);

void tempStats(vector<Temps> temps);