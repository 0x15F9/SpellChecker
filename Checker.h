#ifndef CHECKER_H
#define CHECKER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Checker{

	protected:
		string Word;
		map<string, int> Dictionary;
		vector<string> Matches;

  public:
		Checker();
		Checker(map<string, int> Dic);
		Checker(string W , map<string, int> Dic);
		void setWord(string W);
		void setDictionary(map<string, int> Dic);
		void functionAlteration();
		void functionDeletion();
		void functionInsertion();
		void functionTransposition();
		void functionAlteration(string word);
		void functionDeletion(string word);
		void functionInsertion(string word);
		void functionTransposition(string word);
		vector<string> getMatches();
		vector<string> getMatches(string word);
		~Checker();
};

#endif
