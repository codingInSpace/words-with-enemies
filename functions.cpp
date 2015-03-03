#include "functions.h"

void generate_letters(vector<char>& vec){
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int nLetters = 8;	//the number of letters given

	for (int i = 0; i < nLetters; ++i)
		vec.push_back(*select_randomly(alphabet.begin(), alphabet.end()));
}

void load_dictionary(){
    vector<string> dic;
    ifstream File("/usr/share/dict/linux.words");
    string word;
    
    while(File >> word){
         dic.push_back(word);
    }

    //debug
    cout << "\ndic: ";
	for(vector<string>::iterator it = dic.begin(); it != dic.end(); ++it){
		cout << *it << ",";
	}
	cout << endl;
}