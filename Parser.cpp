#include <fstream>
#include <string>
#include <iostream>
#include <map>

#include "Parser.h"

using namespace std;

Parser::Parser()
{}

Parser::Parser(string path)
{
    this->PopulateDictionary(path);
}

Parser::Parser(string path, string sentence)
{
    this->PopulateDictionary(path);
    this->setSentence(sentence);
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
    Words.clear();
    this->splitSentence(Sentence);
    this->filterWords();
};

void Parser::splitSentence(string sentence)
{
    Words.clear();
    string::size_type prev_pos = 0, pos = 0;
    while( (pos = sentence.find(' ', pos)) != string::npos )
    {
        string substring( sentence.substr(prev_pos, pos-prev_pos) );

        Words.push_back(substring);

        prev_pos = ++pos;
    }

    string substring( sentence.substr(prev_pos, pos-prev_pos) ); // Last word
    Words.push_back(substring) ;
}

void Parser::filterWords()
{
    for(int i = 0; i < Words.size(); i++)
    {
        Words.at(i) = this->Filter(Words.at(i));
    }
}

vector<string> Parser::getWords()
{
    return Words;
}

void Parser::printDictionary()
{  
    int count = 0;
    for(map<string, int>::iterator it=Dictionary.begin(); it!=Dictionary.end(); ++it, count++)
    {
        cout << it->first << " [" << it->second << "]"<< "\t";
        if(count==5)
        {
            cout << endl;
            count = 0;
        }
    }
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
    dataset.close();
}
