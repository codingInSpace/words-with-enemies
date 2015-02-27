#include "canon.h"

int main(){
	//add players
	Canon Player1("jonathan");
	Canon Player2("CPU");

	cout << "debug: p1 points = " << Player1.get_points() << "\np2 points = " << Player2.get_points() << endl;

	//list of words		TO DO: more fair, fixed number of letter words
	string arr[] = {"because", "cause", "hello", "below", "hit", "miss", "rekt", "pwn", "combo", "jumbo", "critical", "optical", "isoenzyme",
					"apoenzyme", "tribesman", "brainstem", "blames", "nimble", "yakuza", "wizard", "longbow", "blowup"};

	//add words to players
	for (int i = 0; i < length(arr); ++i){
		Player1.add_to_vec(arr[i]);
		Player2.add_to_vec(arr[i]);
	}

	Player1.shoot(Player2);

	cout << "debug: p1 points = " << Player1.get_points() << "\np2 points = " << Player2.get_points() << endl;


	return 0;
}