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

void Checker :: setDictionary(map<string, int> Dic){
	Dictionary = Dic;
}

void Checker::functionAlteration(string word){
	string letters = "abcdefghijklmnopqrstuvwxyz";
	string temp;
	for(int i=0; i<word.length(); i++)
	{
		for(int j=0; j<26; j++)
		{
			temp = word;
			temp[i] = letters[j];
			if(Dictionary[temp]>0)
			{
				this->Matches.push_back(temp);
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

vector<string> Checker :: getMatches(string word){
	Matches.clear();
	if(Dictionary[word] > 0)
	{
		Matches.push_back(word);
		Checker :: wordWithHighestOccurence();
		Checker::functionAlteration(word);
		Checker::functionDeletion(word);
		Checker::functionInsertion(word);
		Checker::functionTransposition(word);
	}
	else
	{
		Checker::functionAlteration(word);
		Checker::functionDeletion(word);
		Checker::functionInsertion(word);
		Checker::functionTransposition(word);
		Checker :: wordWithHighestOccurence();
	}
	return Matches;
}

string Checker :: wordWithHighestOccurence()
{
	int PrevCount = 0;
	string ApparentPerfectMatch;
	ApparentPerfectMatch = this->Matches.at(0);
	map<string, int>::iterator it;
	for (it = Dictionary.begin(); it != Dictionary.end(); it++)
		{
			if (ApparentPerfectMatch == it->first)
			{
				PrevCount = it ->second;
			}
		}
	for (int i = 0; i<Matches.size() ;i++)
	{
		for (it = Dictionary.begin(); it != Dictionary.end(); it++)
		{
			if (sizeof(this->Matches.at(i)) == sizeof(it->first))
			{
				if(it->first == (this->Matches.at(i)) )
				{
					if (it->second > PrevCount)
					{
						ApparentPerfectMatch = this->Matches.at(i);
						PrevCount = it ->second;
					}
					}
			}
		}
	}
	wordWithHigestOcurrence = ApparentPerfectMatch;
	return ApparentPerfectMatch;
}

string Checker::getWordWithHighestOccurence()
{
	return wordWithHigestOcurrence;
}

Checker :: ~Checker(){}
