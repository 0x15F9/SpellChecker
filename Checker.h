#ifndef CHECKER_H
#define CHECKER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Checker{

	protected:
		map<string, int> Dictionary;
		vector<string> Matches;
		string wordWithHigestOcurrence;

  public:
		Checker();
		Checker(map<string, int> Dic);
		void setDictionary(map<string, int> Dic);

		void functionAlteration(string word);
		void functionDeletion(string word);
		void functionInsertion(string word);
		void functionTransposition(string word);
		
		vector<string> getMatches();
		vector<string> getMatches(string word);

		string wordWithHighestOccurence();
		string getWordWithHighestOccurence();

		~Checker();
};

#endif
