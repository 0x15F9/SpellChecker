#include <iostream>
#include <string>
#include <vector>
#include <map>
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

	string a = word;
	int w;
	w = a.length();
	string s[w];
	for (int i=0; i<w; i++)
	{
		s[i]=a[i];
	}

	for (int k = 0; k<w; k++)
	{
		for (int l =0; l<26; l++)
		{
			char arr[]="abcdefghijklmnopqrstuvwxyz";
			s[k] = arr[l];
			string ConcatWord="";
			for (int o=0; o<w; o++)
			{
				ConcatWord += s[o];
			}
			if(Dictionary[ConcatWord]>0)
			{
				this->Matches.push_back(ConcatWord);
			}
		}
	}
}

void Checker::functionDeletion(string word){
	
	string a = word; 
	int w = a.length();
	string s[w];
	for (int i=0; i<w; i++)
	{
		s[i]=a[i];
	}
	
	for (int i=0; i<w; i++)
	{
		for (int i=0; i<w; i++)
		{
			s[i]=a[i];
		}
		s[i] = "";
		string ConcatWord="";
		for (int o=0; o<w; o++)
		{
			ConcatWord += s[o];
		}
		if(Dictionary[ConcatWord]>0)
		{
			this->Matches.push_back(ConcatWord);
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
	string a = word; 
	int lw;
	lw = a.length();
	string s[lw];
	for (int i=0; i<lw; i++)
	{
		s[i]=a[i];
	}
	string temp;
	for (int j=0; j<(lw-1); j++)
	{
		temp = s[j];
		s[j] = s[j+1];
		s[j+1] = temp;

		string ConcatWord="";
		for (int o=0; o<lw; o++)
		{
			ConcatWord += s[o];
		}
		if(Dictionary[ConcatWord]>0)
		{
			this->Matches.push_back(ConcatWord);
		}
		for (int i=0; i<lw; i++)
		{
			s[i]=a[i];
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
