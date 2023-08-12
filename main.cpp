#include "Dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

void outputCallback(string anagram);

int main()
{
	Dictionary dict; // Create empty dictionary

	// Build dictionary
	string filename = "words.txt";
	ifstream wordFile(filename);
	string word;
	while (getline(wordFile, word))
		dict.insert(word);

	// Find and print anagrams
	for (;;)
	{
		cout << "Enter a set of letters: ";
		string letters;
		getline(cin, letters);
		if (!cin || letters.empty())
			break;

		cout << "Anagrams of " << letters << ":\n";

		dict.lookup(letters, outputCallback);

		cout << endl;
	}
}

void outputCallback(string anagram)
{
	cout << "  " << anagram;
}