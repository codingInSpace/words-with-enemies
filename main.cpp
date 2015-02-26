#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef> // for std::size_t
#include <random>
#include <iterator>

using namespace std;

template< class T, size_t N >
std::size_t length(const T (&)[N]){
  return N;
};

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

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

	string get_random_word() const {
		string word = *select_randomly(words.begin(), words.end());
		return word;
	}

	void shoot(const Canon& p2){
		string word1 = get_random_word();
		string word2 = p2.get_random_word();

		//debug: print words
		cout << "player1 word: " << word1 << ", player2 word: " << word2 << endl;
	}

private:
	string name;
	vector<string> words; 

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

	Player1.shoot(Player2);

	return 0;
}