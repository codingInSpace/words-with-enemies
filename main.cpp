#include "canon.h"
#include "functions.h"

int main(){
	string exit = "";
	string name = "";
	int roundCounter = 1;
	string tempWord = "";
	vector<char> letters;
	vector<string> dictionary;

	// init dictionary
	load_dictionary(dictionary);

	// add players
	cout << "Your name: ";
	cin >> name;
	Canon Player1(name);
	Canon Player2("CPU");

	// rounds
	while(exit != "n"){
		cout << "===========SCORE===========" << endl;
		cout << Player1.get_name() << ": " << Player1.get_points() << "	" 
			 << Player2.get_name() << ": " << Player2.get_points() << endl;
		cout << "===========SCORE===========" << endl;

		cout << "\n******ROUND " << roundCounter << " START******\n\n";

		// shoot function is if using words-vector
		// Player1.shoot(Player2);

		// generate random letters and store in the vector
		generate_letters(letters);

		// print vector
		cout << "\nYour letters are: ";
		for(vector<char>::iterator it = letters.begin(); it != letters.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;


		do{
		// compose each word
		cout << "\nCompose your word: ";
		cin >> tempWord;
		
			while(!validate_letters(tempWord, letters)){
				cout << "\nYou got the letters wrong, do it again: ";
				cin >> tempWord;
			}

		}while(!validate_word(tempWord, dictionary));

		// new shoot functionality
		// ...

		cout << "\nKeep playing? (y/n)" << endl;
		cin >> exit;
	}
	return 0;
}
