#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Checker.h"

using namespace std;

Checker :: Checker(){}

Checker :: Checker(map<string, int> Dic){
  	Dictionary = Dic; 
}

Checker :: Checker(string W , map<string, int> Dic){
	Word = W;
  	Dictionary = Dic; 
}

void Checker :: setWord(string W){
	Word = W;
}

void Checker :: setDictionary(map<string, int> Dic){
	Dictionary = Dic;
}

void Checker::functionAlteration(string word){

	int count =0;
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int word_length = word.size();
	string w;
	word = " " + word + " ";
	for(int j=0; j<=word_length; j++)
	{
		int pos = j+2;
		int length2 = word_length-j;
		for(int x=0; x<letters.size(); x++)
		{
				w = word.substr(0, pos-1)+letters[x]+word.substr(pos, length2);
				
				if(count<(26*(word_length))){
				w = w.substr(0, w.size()-1);
				if(Dictionary[w]>0)
				{
					this->Matches.push_back(w);
				}
				count++;
				}
		}
	}
}

void Checker::functionDeletion(string word){
	string w;
	int word_length = word.size();

	for(int j=0; j<=word_length-1; j++){
		w = Word;
		w[j] = '-';
		w.erase (remove(w.begin(), w.end(), '-'), w.end());
		if(Dictionary[w]>0)
		{
			this->Matches.push_back(w);
		}
	}
}

void Checker::functionInsertion(string word){
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int word_size = word.size();
	int i = 0;
	string w;

	for(int j=0; j<=word_size; j++)
	{
		int length1 = j;
		int length2 = word_size-j;
		for(int x=0; x<letters.size(); x++)
		{
			w = word.substr(0, length1)+letters[x]+word.substr(j, length2);
			if(Dictionary[w]>0)
			{
				this->Matches.push_back(w);
			}
			i++;
		}
	}
}

void Checker :: functionTransposition(string word){
	string w;
	int word_length = word.size();
	char temp;
	for(int j=0; j<=word_length-2; j++){
			w = Word;
			temp = w[j];
			w[j] = w[j+1];
			w[j+1] = temp;
			if(Dictionary[w]>0)
			{
				this->Matches.push_back(w);
			}
	}
}


void Checker::functionAlteration()
{
	this->functionAlteration(this->Word);
};

void Checker::functionDeletion()
{
	this->functionDeletion(this->Word);
};

void Checker::functionInsertion()
{
	this->functionInsertion(this->Word);
};

void Checker::functionTransposition()
{
	this->functionTransposition(this->Word);
};

vector<string> Checker :: getMatches()
{
	return this->getMatches(this->Word);
}

vector<string> Checker :: getMatches(string word){
	Matches.clear();
	// if(Dictionary[word] > 0)
	// {
	// 	Matches.push_back(word);
	// 	return Matches;
	// }
	// else
	{
		this->functionAlteration(word);
		this->functionDeletion(word);
		this->functionInsertion(word);
		this->functionTransposition(word);
		return Matches;
	}
}

Checker :: ~Checker(){}

