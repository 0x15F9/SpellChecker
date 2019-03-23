#include <iostream>
#include <string>

using namespace std;

int main() 
{
	cout<<"Mauritius"<<endl;

	string a = "Mauritius"; 
	int w;
	w = a.length();
	string s[w];
	for (int i=0; i<w; i++)
	{
		s[i]=a[i];
	}

	string temp;
	for (int j=0; j<(w-1); j++)
	{
		temp = s[j];
		s[j] = s[j+1];
		s[j+1] = temp;
		for (int i=0; i<w; i++)
		{
			cout<<s[i];
		}
		cout<<endl;
		for (int i=0; i<w; i++)
		{
			s[i]=a[i];
		}
	}
	return 0;
}
