#include <iostream>
#include <string>

using namespace std;

int main() 
{
cout<<"mauritius"<<endl;

	string a = "mauritius"; 
	int w;
	w = a.length();
	cout<<w<<endl;
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
			for (int m = 0; m<10; m++)
			{
					cout<<s[m];
			}
				cout<<endl;
 			}
			cout<<endl;
			s[k] = a[k];		
	}
return 0;
}
