#include "functions.h"

void generate_letters(vector<char>& vec){
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int nLetters = 8;	//the number of letters given

	for (int i = 0; i < nLetters; ++i)
		vec.push_back(*select_randomly(alphabet.begin(), alphabet.end()));
}

void load_dictionary(vector<string>& dic){
    ifstream File("/usr/share/dict/linux.words");
    string word;
    
    while(File >> word){
         dic.push_back(word);
    }
}

bool validate_letters(string word, vector<char> vec){
	// bool to be returned initially true

	// loop through word
		// for each letter, loop through vec
			// if letter found in vec, break
			// else set false at end of for-loop
}

bool validate_word(string word, vector<string> dic){
	// loop through dic
		// if word found, return true
		// else print message and return false
}
