#include "FileReader.hh"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

void FileReader(string name_of_the_file, string anag_me){
	ifstream the_file(name_of_the_file);
	string line;
	map<char, int> lettercount_word;
	map<char, int> lettercount;
	vector<string> matching_words;


	vector < map<char, int> > all_words;
	vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
		'x', 'y', 'z'};



	for (char c : letters) {
		int temp = count(anag_me.begin(), anag_me.end(), c);
		lettercount_word[c] = temp;
	}

	while (!the_file.eof()){
		
		the_file >> line;
		
		if (line == "crawls") {
			cout << "25% of search done\n";
		}

		else if (line == "labyrinth") {
			cout << "50% of search done\n";
		}

		else if (line == "seceding") {
			cout << "75% of search done\n";
		}

		for (char c : letters) {
			int temp = count(line.begin(), line.end(), c);
			lettercount[c] = temp;
		}
		map<char, int>::iterator iter_randomword = lettercount.begin();
		map<char, int>::iterator iter_theword = lettercount_word.begin();
		bool same{ true };

		while (iter_randomword != lettercount.end()) {
			if (iter_randomword->second != iter_theword->second) {
				same = false;
			}
			iter_randomword++;
			iter_theword++;
		}
		if (same) {
			matching_words.push_back(line);
		}
		
	}
	cout << "Search done!\nMatching words are:\n ";
	for (auto word : matching_words) {
		cout << word << "\n ";
	}
	cout << "Press enter to exit." << endl;

	getline(cin, line);
}

