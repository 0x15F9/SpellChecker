
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout<<"Mauritius"<<endl;

	string a = "Mauritius"; 
	int w = a.length();
	string s[w];
	for (int i=0; i<w; i++)
	{
		s[i]=a[i];
	}

  cout<<endl;
	
	for (int i=0; i<w; i++)
	{

		for (int i=0; i<w; i++)
		{
			s[i]=a[i];
		}

		s[i] = "";
		for (int i=0; i<w; i++)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
