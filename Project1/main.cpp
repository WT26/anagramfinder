#include "FileReader.hh"
#include <string>
#include <iostream>

int main() {
	string line;
	cout << "Find anagrams for word: ";
	getline(cin, line);
	FileReader("English_words.txt", line);
}