#include "Morse Code Converter.h"
#include <iostream>
using namespace std;
void plainInput(Morse_Code_Converter mc)
{
	ifstream plainTextIn("plain text in.txt");
	ofstream morseCodeOut("morse code out.txt");
	if (plainTextIn.fail())
	{
		cout << "The input file 'plain text in.txt' failed on opening.\n";
		exit(1);
	}
	string line;
	while (!plainTextIn.eof())
	{
		getline(plainTextIn, line);
		cout << "\n" << line << '\n';
		line = mc.encode(line);
		cout << line << '\n';
		morseCodeOut << line << '\n';
	}
	plainTextIn.close();
	morseCodeOut.close();
}

void morseInput(Morse_Code_Converter mc)
{
	ifstream morseTextIn("morse text in.txt");
	ofstream plainTextOut("plain text out.txt");
	if (morseTextIn.fail())
	{
		cout << "The input file 'plain text in.txt' failed on opening.\n";
		exit(1);
	}
	string line, morseLetter;
	while (!morseTextIn.eof())
	{
		getline(morseTextIn, line);
		cout << '\n' << line << '\n';
		for (char& c : line)
		{
			if (c == '.' || c == '_')
			{
				morseLetter += c;
			}
			else
			{
				morseLetter = mc.decode(morseLetter);
				cout << morseLetter << ' ';
				plainTextOut << morseLetter << ' ';
				morseLetter = "";
			}
		}
		cout << '\n';
		plainTextOut << '\n';
	}
	morseTextIn.close();
	plainTextOut.close();
}
void main() {
	Morse_Code_Converter MC;
	MC.process();
	MC.postorderPrint();
	plainInput(MC);
	morseInput(MC);
	
	
	system("PAUSE");
}