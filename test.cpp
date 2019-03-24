#include "Parser.h"
#include "Checker.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string w, word;
    string path="/home/isfaaq/Documents/School/BSc-CS/Spell Checker/Datasets/sherlock holmes.txt";
    
    map<string, int> Dictionary;
    vector<string> matches;

    cout << "Word: ";
    getline(cin, w);
    
    Parser parser;
    parser.PopulateDictionary(path);
    Dictionary = parser.getDictionary();
    Checker checker(word, Dictionary);
    matches = checker.getMatches();


    // parser.printDictionary();
    for(int i = 0; i < parser.getWords().size(); i++)
    {
        word = parser.getWords().at(i);
        matches = checker.getMatches(word);
        cout << word << " :" <<endl;

        // for(int j = 0; j < matches.size(); j++)
        // {
        //     cout << matches.at(j) << endl;
        // }
        
        
    }
    
    return 0;
}