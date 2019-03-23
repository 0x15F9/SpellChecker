#include <fstream>
#include <string>
#include <iostream>
#include <map>

#include "Parser.h"

using namespace std;

Parser::Parser()
{}

Parser::Parser(string path, string sentence)
{
    this->PopulateDictionary(path);
    this->Sentence = sentence;
}

map<string, int> Parser::getDictionary()
{
    return Dictionary;
}

string Parser::getSentence()
{
    return Sentence;
};

void Parser::setSentence(string Sentence)
{
    this->Sentence = Sentence;
};

void Parser::printDictionary()
{
    for(map<string, int>::iterator it=Dictionary.begin(); it!=Dictionary.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
}

string Parser::Filter(string word)
{
    string new_word = "";
    int symbol_count = 0;
    // For each character in the string
    for(int i=0; i<word.size(); i++)
    {
        int character = (int) word.at(i);
        // if it is upper case, convert to lowercase
        if(character>=65 && character<=90) 
        {
            new_word = new_word + (char) (character+32);
        }
        // if it is lower case, add it
        else if(character>=97 && character<=122)
        {
            new_word = new_word + (char) character;
        }
        else // otherwise, increase symbol count
        {
            symbol_count++;
        }
        if (symbol_count>2) return "";
    }
    return new_word;
}

void Parser::PopulateDictionary(string pathname)
{
    ifstream dataset(pathname.c_str());

    string word;
    string new_word;

    while(!dataset.eof())
    {
        dataset >> word;

        new_word = this->Filter(word);
        // Words which are to be rejected have been returned as empty strings
        if (new_word != "")
        {
            // If dictionary does not contain a word, add it
            if(Dictionary.find(new_word)->second == 0)
            {
                Dictionary[new_word] = 1;
            } 
            // otherwise increment it
            else
            {
                Dictionary[new_word] = Dictionary[new_word]+1;
            }
        }
    }

}