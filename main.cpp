#include "Parser.h"
#include "Checker.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

int main()
{
    map<string, int> Dictionary;
    vector<string> matches, words;
    string word;
    string path="/home/isfaaq/Documents/School/BSc-CS/Spell Checker/Datasets/sherlock holmes.txt";

    cout << "sentence: ";
    getline(cin, word);

    Parser parser(path, word);

    // parser.PopulateDictionary("/home/isfaaq/Documents/School/BSc-CS/Spell Checker/Datasets/small.txt");
    Dictionary = parser.getDictionary();
    Checker checker(Dictionary);

    words = parser.getWords();
    for(int j = 0; j < words.size(); j++)
    {
        matches = checker.getMatches(words.at(j));
        cout << endl << words.at(j) << ": " << endl;
        for(int i = 0; i < matches.size(); i++)
        {
            cout << matches.at(i) << endl;
        }
    }

    return 0;
}