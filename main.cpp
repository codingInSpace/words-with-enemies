#include <iostream>
#include <algorithm>
#include <vector>

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

int main(){
	//add players
	Canon P1("jonathan");

	//test adding words
	P1.add_to_vec("first");
	P1.add_to_vec("second");
	P1.add_to_vec("third");

	P1.display_vec();



	return 0;
}