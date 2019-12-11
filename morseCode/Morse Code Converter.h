#pragma once
#include "Morse Code Tree.h"
#include "Morse Cross Hash Table.h"

class Morse_Code_Converter {
private:
	MorseCodeTree morseTree;	//MorseTree for decoding
	MorseCrossHash morsecrosshash;//MorseHash for encoding
	void postPrint(BTNode* p, int indent = 0);
public:
	//Default constructor
	Morse_Code_Converter() {
		morseTree = MorseCodeTree();
	}

	//Member Functions
	void process();
	string search(BTNode *&node, string in);
	string decode(string in);
	string encode(string in);
	void postorderPrint();
};
