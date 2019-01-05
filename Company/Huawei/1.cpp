#include<iostream>
#include<string>
//找一串数字中最大的三位数

using namespace std;
int main()

{
	string s;
	while(cin >> s)
	{
		int size = s.size();
		int max = 0,index = 0;
		if(size < 4)
		{
			cout<<s<<endl;
			continue;
		}
		for(int i = 0;i < size - 2;i++)
		{
			int now = s[i] - 48;
			if( now > max )
			{
				max = now;
				index = i;
			}
		}
		for(int i = index;i < index + 3;i++)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}