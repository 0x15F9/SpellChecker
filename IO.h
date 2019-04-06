#ifndef H_IO
#define H_IO

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Parser.h"
#include "Checker.h"

using namespace std;

class IO
{
protected:
	map<string, string> alternative;
    Parser parser;
    Checker checker;

public:
    IO();

    int displayMenu();
    void loop();
		void getValidSentence();
    void match();
    void viewDictionary();
		void CalcOccurences();
    void addDictionary();
    void about();
    void invalidChoice();
};

#endif
