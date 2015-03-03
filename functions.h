#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "canon.h"
#include <fstream>
#include <vector>


void generate_letters(vector<char>& vec);

void load_dictionary(vector<string>& dic);

bool validate_letters(string word, vector<char> vec);

bool validate_word(string word, vector<string> dic);



#endif
