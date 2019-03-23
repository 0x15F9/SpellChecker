#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>
#include <string>

using namespace std;

class Parser
{
protected:
    map<string, int> Dictionary;
    string Sentence;
    vector<string> Words;

public: 
    Parser();
    Parser(string pathname, string sentence);

    map<string, int> getDictionary();
    void printDictionary();

    string getSentence();
    void setSentence(string Sentence);

    string Filter(string word);
    void PopulateDictionary(string pathname);

};

#endif