#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef> // for std::size_t


using namespace std;

class Canon{
public:
	Canon()
	: name("Unidentified player"){}

	Canon(string name)
	: name(name){}

	void add_to_vec(string word){
		words.push_back(word);
	}

	void display_vec(){
		for(vector<string>::const_iterator i = words.begin(); i != words.end(); ++i)
    		cout << *i << " ";	

    	cout << endl;
	}

	string shoot_random_word(){
		string word = "";

		//select random element in vec

		return word;
	}

private:
	string name;
	vector<string> words; 

};

template< class T, size_t N >
std::size_t length(const T (&)[N]){
  return N;
};

int main(){
	//add players
	Canon Player1("jonathan");
	Canon Player2("CPU");

	//list of words		TO DO: more fair, fixed number of letter words
	string arr[] = {"because", "cause", "hello", "below", "hit", "miss", "rekt", "pwn", "combo", "jumbo", "critical", "optical", "isoenzyme",
					"apoenzyme", "tribesman", "brainstem", "blames", "nimble", "yakuza", "wizard", "longbow", "blowup"};

	//add words to players
	for (int i = 0; i < length(arr); ++i){
		Player1.add_to_vec(arr[i]);
		Player2.add_to_vec(arr[i]);
	}

	// Player1.display_vec();	

	


	return 0;
}