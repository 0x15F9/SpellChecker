#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Checker.h"


using namespace std;

Checker :: Checker(){}

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

void Checker :: functionAlteration(){

	string a = this->Word; 
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
			if(Dictionary.find(ConcatWord)>0)
			{
				this->Matches.push_back(ConcatWord);
			}
		}
	}
}

void Checker :: functionDeletion(){
	
	string a = this->Word; 
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
		for (int o=0; o<w; o++)
		{
			ConcatWord += s[o];
		}
		if(Dictionary.find(ConcatWord)>0)
		{
			this->Matches.push_back(ConcatWord);
		}
	}
}

void Checker :: functionInsertion(){
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int word_size = Word.size();
	int i = 0;
	string w;

	for(int j=0; j<=word_size; j++)
	{
			int length1 = j;
			int length2 = word_size-j;
			for(int x=0; x<letters.size(); x++)
			{
					w = Word.substr(0, length1)+letters[x]+Word.substr(j, length2);
					if(Dictionary.find(w)>0)
					{
						this->Matches.push_back(ConcatWord);
					}
					i++;
			}
	}
}

void Checker :: functionTransposition(){
	string a = this->Word; 
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
		for (int o=0; o<w; o++)
		{
			ConcatWord += s[o];
		}
		if(Dictionary.find(ConcatWord)>0)
		{
			this->Matches.push_back(ConcatWord);
		}
		for (int i=0; i<lw; i++)
		{
			s[i]=a[i];
		}
	}
}

vector<string> Checker :: getMatches(){
	if(this->Dictionary.find(this->Word) > 0)
	{
		Matches.push_back(this->Word)
		return Matches;
	}
	{
		this->functionAlteration();
		this->functionDeletion();
		this->functionInsertion();
		this->functionTransposition();
		return Matches;
	}
}

Checker :: ~Checker(){}
