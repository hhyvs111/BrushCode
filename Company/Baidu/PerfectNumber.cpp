#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int cnt = 0;
		//这里不能为i不能为0啊，不能0%0，怪不得出错。
		for(int i = 1 ; i < n;i++)
		{
			if(n%i == 0)
				cnt += i;
		}
		if(cnt == n)
			cout << "1" << endl;
		else
			cout << "2" << endl;
	}
	return 0;
}