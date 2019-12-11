#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class MorseCrossHash {
private:
	unordered_map<string, string> letterMap;
public:
	//Default constructor
	MorseCrossHash(){}

	//Member Functions
	void add_letter(string letter, string morse) {
		//adds hash table based on given line
		letterMap[letter] = morse;
	};

	// does a lookup and returns the morse version of the letter
	string getMorse(string letter) {
		return letterMap[letter];
	};
};