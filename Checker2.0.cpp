#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Checker.h"

using namespace std;

Checker :: Checker(){}

Checker :: Checker(map<string, int> Dic){
  	Dictionary = Dic; 
}


void Checker :: setDictionary(map<string, int> Dic){
	Dictionary = Dic;
}

vector<string> Checker :: getMatches(string word){
	Matches.clear();
	// if(Dictionary[word] > 0)
	// {
	// 	Matches.push_back(word);
	// 	return Matches;
	// }
	// else
	{
		this->functionAlteration(word);
		this->functionDeletion(word);
		this->functionInsertion(word);
		this->functionTransposition(word);
		return Matches;
	}
}

Checker :: ~Checker(){}

