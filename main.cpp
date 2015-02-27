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

	string get_name() const{
		return name;
	}

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
		cout << "\n***ROUND START***\n";
		string word1 = get_random_word();
		string word2 = p2.get_random_word();

		//print words
		cout << get_name() << "\'s word: " << word1 << endl
			 << p2.get_name() << "\'s word: " << word2 << endl;

		vector<char> charsToRemove;

		for(string::iterator it1 = word1.begin(); it1 != word1.end(); ++it1) {
			for(string::iterator it2 = word2.begin(); it2 != word2.end(); ++it2) {
				if((*it1 == *it2) and (*it1)){
					// char c1 = *it1;
					// char c2 = *it2;
					// cout << "debug: it1 = " << c1 << ", it2 = " << c2 << endl;

					charsToRemove.push_back(*it1);
				}
			}
		}

		//remove letters from words
		for(vector<char>::iterator it = charsToRemove.begin(); it != charsToRemove.end(); ++it){
			word1.erase(remove(word1.begin(), word1.end(), *it), word1.end());
			word2.erase(remove(word2.begin(), word2.end(), *it), word2.end());
		}

		cout << "\nBOOM\n";
		cout << "\nAftermath:\n" << get_name() << "\'s word: " << word1 << endl
			 << p2.get_name() << "\'s word: " << word2 << endl << endl;
	
		int nLetters1 = 0;
		int nLetters2 = 0;

		//count letters
		for(string::iterator it1 = word1.begin(); it1 != word1.end(); ++it1)
			nLetters1++;
		for(string::iterator it2 = word2.begin(); it2 != word2.end(); ++it2)
			nLetters2++;

		// calc winner
		if (nLetters1 > nLetters2){			//p1 wins
			cout << get_name() << " wins with " << (nLetters1 - nLetters2) << " remaining letters more than " << p2.get_name() << endl;
		}

		else if(nLetters2 > nLetters1){		//p2 wins
			cout << p2.get_name() << " wins with " << (nLetters2 - nLetters1) << " remaining letters more than " << get_name() << endl;

		}

		else if (nLetters1 == nLetters2){	//draw
			cout << "It's a draw!" << endl;
		}

		else
			cout << "error" << endl;

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