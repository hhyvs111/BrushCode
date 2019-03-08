#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	string str;
	while(cin >> str)
	{
		int ans = 0;
		stack<char> s;
		s.push(str[0]);
		int size = str.size();
		int i = 0;
		while(!s.empty() && i < size)
		{
			if(i < size && (str[i] == '{' || str[i] == '<'))
			{
				s.push(str[i++]);
				continue;
			}
			char now = s.top();
			if(i < size)
			{
				cout << str[i] << endl;
				cout << now << endl;
				if((str[i] == '}' && now == '<') || (str[i] == '>' && now == '{') || (str[i] == '>'))
				{
					s.pop();
					ans++;
				}
				else
				{
					if((str[i] == '}' && now == '{') || (str[i] == '<' && str[i] == '>'))
					{
						s.pop();
						i++;
					}
				}
			}
		}
		cout << s.size() << endl;
		cout << ans + s.size() <<endl;
	}
	return 0;
}