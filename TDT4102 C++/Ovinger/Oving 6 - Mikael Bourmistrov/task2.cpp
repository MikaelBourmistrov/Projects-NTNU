#include "std_lib_facilities.h"
#include "task2.h"

//const map<char , int> alphabetCharacters { {'a', 0}, {"b", 1} , {"c", 2} , {"d", 3}, {"e", 4}, {"f", 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24}, {'z', 25} };

void countCharInText(string filePath) {
    ifstream innFile;
    string line, simpleFile;
    vector<int> amountChars(26);

    innFile.open(filePath);
	if (!innFile) {
		error("Klarer ikke aa aapne filen ", filePath);
		return;
	}

	while (!innFile.eof()) {
		getline(innFile, line);
		simpleFile += line;
	}

	for (char character : simpleFile) {
		if (character <= 123 && isalpha(character))
			amountChars[tolower(character) - 'a'] += 1;
	}

	for (int i = 0; i < amountChars.size(); i += 3) {
		for (int j = i; (j < (i+3)) && (j < amountChars.size()); ++j) {
			cout << char(j+'a') << ":" << setw(8) << amountChars[j] << "\t";
		}
		cout << endl;
	}
}