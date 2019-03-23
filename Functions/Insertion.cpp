#include <iostream>
#include <string>

using namespace std;

int main() 
{
	cout<<"mauritius"<<endl;

	string a = "mauritius"; 
	int w;
	w = a.length();
	w = w + (a.length() + 1);
	string s[w];

	for (int j = 0; j<=(w+2); j=j+2)
	{
		s[j] = " ";
	}
  int j = 0;
	for (int i=0; i<w; i++)
	{
		int check = i%2;
		cout<<check<<endl;
		
		if ((check) == 1)
		{	
		s[i]=a[j];
		j+=1;
		}

	}
	for (int m = 0; m<w; m++)
	{
		cout<<s[m];	
	}

  cout<<endl;

	for (int k = 0; k<w; k++)
	{
		if (s[k] == " ")
		{
			for (int l =0; l<26; l++)
			{
				char arr[]="abcdefghijklmnopqrstuvwxyz";
  			s[k] = arr[l];

				for (int m = 0; m<w; m++)
				{
					if (s[m] != " ")
					{
						cout<<s[m];
					}
				}
				cout<<endl;
			}
			s[k] = " ";
		}
	}
	return 0;
}
