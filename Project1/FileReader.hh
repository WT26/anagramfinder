#ifndef FILEREADER_HH
#define FILEREADER_HH

#include <string>
#include <map>

using namespace std;

void FileReader(string name_of_the_file, string anag_me);
void search_phase(string line);
map<char, int> lettercount_for_the_word(vector<char> letters, string line);


#endif // FILEREADER_HH
