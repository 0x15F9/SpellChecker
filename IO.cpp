#include <iostream>
#include <string>

#include "IO.h"
#include "Parser.h"
#include "Checker.h"

using namespace std;

IO::IO()
{
    parser = Parser("./Dataset/SherlockHolmes.txt");
    checker = Checker(parser.getDictionary());
}

int IO::displayMenu()
{
    int choice;

    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------              SpellChecker              ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "| > Choose from the following:                       |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "|   1. Input Sentence                                |" << endl;
    cout << '\t' << "|   2. Show alternatives for a word                  |" << endl;
    cout << '\t' << "|   3. View dictionary                               |" << endl;
    cout << '\t' << "|   4. View number of occurences of a word           |" << endl;
    cout << '\t' << "|   5. Add another dictionary                        |" << endl;
    cout << '\t' << "|   7. About                                         |" << endl;
    cout << '\t' << "|   8. Exit                                          |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > Choice: ";
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

void IO::loop()
{
    int choice;
    while(true)     
    {
        choice = IO::displayMenu();
        if(choice==1) this->getValidSentence();
        else if(choice==2) this->match();
        else if(choice==3) this->viewDictionary();
				else if (choice==4) this->CalcOccurences();
        else if (choice==5) this->addDictionary();
        else if (choice==7) this->about();
        else if (choice==8) break;
        else this->invalidChoice();
    }
    
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------                   Bye                  ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;
}

void IO::getValidSentence()
{
    string sentence;
    string finalSentence = "";
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------             Input Sentence             ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > ";
    getline(cin, sentence);
    parser.setSentence(sentence);

    vector<string> matches,words;
    words = parser.getWords();

    for(int j = 0; j < words.size(); j++)
    {
        matches = checker.getMatches(words.at(j));
        finalSentence += checker.wordWithHighestOccurence() + " ";
    }

    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------           Alternate Sentence           ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > ";
    cout << finalSentence << endl;

    cout << endl;
}

void IO::match()
{
    string word;
    vector<string> matches;

    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------               Input Word               ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > ";
    getline(cin, word);
    matches = checker.getMatches(word);
    cout << endl;

    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------                Matches                 ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > ";
    for(vector<string>::iterator it = matches.begin(); it != matches.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;

    cout << endl;
}

void IO::viewDictionary()
{
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------               Dictionary               ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    parser.printDictionary();

    cout << endl;
    cout << endl;
}

void IO::CalcOccurences()
{
	int count, found = 0;
	string word;
	map<string, int> Dic;

	cout << '\t' << "+====================================================+" << endl;
	cout << '\t' << "|------               Input Word               ------|" << endl;
	cout << '\t' << "+====================================================+" << endl;
	cout << endl;

	cout << '\t' << "  > ";
	getline(cin, word);
	Dic = parser.getDictionary();
	cout << endl;

	map<string, int>::iterator it;
	for (it = Dic.begin(); it != Dic.end(); it++)
	{
		if (word == it->first)
		{
			count = it->second;
			found = 1;
		}
	}
	
	if (found == 1)
	{
		cout << '\t' << "+====================================================+" << endl;
		cout << '\t' << "|------          Number Of Occurences          ------|" << endl;
		cout << '\t' << "+====================================================+" << endl;
		cout << endl;
		cout << '\t' << "  > ";
		cout << "Number of occurences for the word is : "<<count;
		cout << endl;
		cout << endl;
	}
	else
	{
		cout << '\t' << "+====================================================+" << endl;
		cout << '\t' << "|------            ERROR: NOT FOUND            ------|" << endl;
		cout << '\t' << "+====================================================+" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void IO::addDictionary()
{
    string path;
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------             Add Dictionary             ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;

    cout << '\t' << "  > Path: ";
    getline(cin, path);
    parser.PopulateDictionary(path);
    cout << endl;
}

void IO::about()
{
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------                 About                  ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "| > Authors                                          |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "|   - Isfaaq Goomany                                 |" << endl;
    cout << '\t' << "|   - Yoveer Mungun                                  |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "| > Acknowledgement                                  |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "|   - A large part of the logic is inspired from     |" << endl;
    cout << '\t' << "|   Peter Norvig's article.                          |" << endl;
    cout << '\t' << "|   - http://norvig.com/spell-correct.html           |" << endl;
    cout << '\t' << "|                                                    |" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;
}

void IO::invalidChoice()
{
    cout << '\t' << "+====================================================+" << endl;
    cout << '\t' << "|------             Invalid Choice             ------|" << endl;
    cout << '\t' << "+====================================================+" << endl;
    cout << endl;
}
