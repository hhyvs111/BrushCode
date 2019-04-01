#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		string s;
		cin >> s;
		int size = s.size();
		for(int i = 0; i < size;i++)
		{
			//AAA
			if(((i < size - 2)&&(s[i] == s[i + 1] && s[i + 1] == s[i + 2])) || ((i < size - 3)&&(s[i] == s[i + 1] && s[i + 2] == s[i + 3])))
			{
				// cout << s[i] << s[i+1] << s[i+2] << s[i+3] << endl;
				for(int j= i+2; j < s.size() - 1;j++)
				{
					s[j] = s[j+1];
				}
				size--;
				i--;
			}
		}
		for(int i = 0 ; i < size;i++)
		{
			cout << s[i] ;

		}
		cout << endl;
	}
	return 0;
}