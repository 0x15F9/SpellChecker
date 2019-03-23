#include "Parser.h"
#include "Checker.h"
#include <string>
#include <iostream>
#include <map>

int main()
{
    map<string, int> Dictionary;
    string word;

    cout << "word: ";
    cin >> word;

    Parser parser;

    parser.PopulateDictionary("/home/isfaaq/Documents/School/BSc-CS/Spell Checker/Datasets/small.txt");
    Dictionary = parser.getDictionary();
    // parser.printDictionary();

    Checker checker(word, Dictionary);

    // for(int i=0; i<checker.getMatches().size(); i++)
    // {
        cout << checker.getMatches().at(0) << endl;
    // }
    
    return 0;
}