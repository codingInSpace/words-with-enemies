#include "canon.h"
#include "functions.h"

int main(){
	string exit = "";
	string name;
	int roundCounter = 1;

	//add players
	cout << "Your name: ";
	cin >> name;

	Canon Player1(name);
	Canon Player2("CPU");

	// //add words to players
	// for (int i = 0; i < length(arr); ++i){
	// 	Player1.add_to_vec(arr[i]);
	// 	Player2.add_to_vec(arr[i]);
	// }

	//add letters to vector
	vector<char> letters;
	generate_letters(letters);

	//debug: print vector
	cout << "\nletter vector:";
	for(vector<char>::iterator it = letters.begin(); it != letters.end(); ++it){
		cout << *it << ", ";
	}
	cout << endl;

	//rounds
	while(exit != "n"){
		cout << "===========SCORE===========" << endl;
		cout << Player1.get_name() << ": " << Player1.get_points() << "	" 
			 << Player2.get_name() << ": " << Player2.get_points() << endl;
		cout << "===========SCORE===========" << endl;

		cout << "\n******ROUND " << roundCounter << " START******\n\n";

		Player1.shoot(Player2);

		cout << "\nKeep playing? (y/n)" << endl;
		cin >> exit;
	}
	return 0;
}
