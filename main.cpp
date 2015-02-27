#include "canon.h"

int main(){

	string exit = "";
	string name;
	int roundCounter = 1;

	//add players
	cout << "Your name: ";
	cin >> name;

	Canon Player1(name);
	Canon Player2("CPU");

	//list of words		TO DO: more fair, fixed number of letter words
	string arr[] = {"because", "cause", "hello", "below", "hit", "miss", "rekt", "pwn", "combo", "jumbo", "critical", "optical", "isoenzyme",
					"apoenzyme", "tribesman", "brainstem", "blames", "nimble", "yakuza", "wizard", "longbow", "blowup"};

	//add words to players
	for (int i = 0; i < length(arr); ++i){
		Player1.add_to_vec(arr[i]);
		Player2.add_to_vec(arr[i]);
	}

	//rounds
	while(exit != "n"){
		cout << "===========SCORE===========" << endl;
		cout << Player1.get_name() << ": " << Player1.get_points() << "		" 
			 << Player2.get_name() << ": " << Player2.get_points() << endl;
		cout << "\n***ROUND " << roundCounter < "***\n";
		
		Player1.shoot(Player2);

		cout << "\nKeep playing? (y/n)" << endl;
		cin >> exit;
	}
	return 0;
}