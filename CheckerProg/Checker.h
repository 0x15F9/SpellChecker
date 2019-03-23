#ifndef CHECKER_H
#define CHECKER_H

//#include "Parser.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class Checker{ //: Parser{

	protected:
						string Word;
						map<string, int> Dictionary;
						vector<string> Matches;

  public:
					Checker();
					Checker(string W , map<string, int> Dic);
					setWord(string W);
					setDictionary(map<string, int> Dic);
					functionAlteration(string W, vector<string> M);
					functionDeletion(string W, vector<string> M);
					functionInsertion(string W, vector<string> M);
					functionTransposition(string W, vector<string> M);
					vector<string> getMatches();
					~Checker();
};

#endif
