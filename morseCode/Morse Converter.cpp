#include "Morse Code Converter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#define COUNT 10
using namespace std;

void Morse_Code_Converter::process() {
	//Reads in morse.txt, builds MorseTree and MorseHash
	ifstream morse;
	morse.open("morse.txt");
	string line = "";

	while (!morse.eof()) {
		//Read in the line, pass into the respective add_letter functions that will build the tree/hash
		morse >> line;
		string letter = line.substr(0, 1);
		string code = line.substr(1);
		BTNode *morse_root = morseTree.get_root();
		morseTree.add_letter(morse_root, code, letter);
		morsecrosshash.add_letter(letter, code);
	}
	morse.close();
	
}
void Morse_Code_Converter::postorderPrint()
{
	BTNode* p = morseTree.get_root();
	postPrint(p);
}
void Morse_Code_Converter::postPrint(BTNode* root, int space)
{
	// Base case  
		if (root == NULL)
			return;

		// Increase distance between levels  
		space += COUNT;

		// Process right child first  
		postPrint(root->right, space);

		// Print current node after space  
		// count  
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->data << "\n";

		// Process left child  
		postPrint(root->left, space);
}



string Morse_Code_Converter::search(BTNode *&node, string in) {
	//Takes in a string of morse code, converts to letters [delimeter = space]
	if (node->data != "" && in.size() == 0) {
		return node->data;
	}
	else if (in.at(0) == '.') {
		return search(node->left, in.substr(1));
	}
	else if (in.at(0) == '_'){
		return search(node->right, in.substr(1));
	}
	else if (node == NULL) {
		return "";
	}
	else {
		return "Invalid morse string";
	}
}


string Morse_Code_Converter::decode(string in) {
	//Calls the search function to decode the string
	char token = ' ';
	string code = "";
	BTNode *root = morseTree.get_root();
	string result = "";

	for (int i = 0; i < in.size(); i++) {
		token = in[i];
		if (token != ' ') {
			code += token;
			if (i == in.size() - 1) {
				result += search(root, code);
			}
		}
		else if (token == ' ') {
			result += search(root, code);
			code = "";
		}
	}
	return result;
}

string Morse_Code_Converter::encode(string in) {
	//Takes in a string of letters, converts to morse code	[delimeter = space]
	string result = "";
	string letter;
	for (string::iterator iter = in.begin(); iter != in.end(); iter++) {
		letter = *iter;
		result.append(morsecrosshash.getMorse(letter));
		result.append(" ");
	}
	return result;
}