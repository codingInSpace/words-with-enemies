#include "functions.h"

void generate_letters(vector<char>& vec){
	// char alphabet[] = {
	// 'a','b','c','d',
	// 'e','f','g','h',
	// 'i','j','k','l',
	// 'm','n','o','p',
	// 'q','r','s','t',
	// 'u','v','w','x',
	// 'y','z'
	// };

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int nLetters = 8;	//the number of letters given

	for (int i = 0; i < nLetters; ++i){	
		vec.push_back(*select_randomly(alphabet.begin(), alphabet.end()));
	}
}
