#ifndef CANON_H
#define CANON_H

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

	string get_name() const;

	void add_to_vec(string word);

	void display_vec();

	string get_random_word() const;

	void shoot(const Canon& p2);

private:
	string name;
	vector<string> words; 

};


#endif
