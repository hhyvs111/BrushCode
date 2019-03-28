#include<bits/stdc++.h>
using namespace std;
char martex[][] = new char[65535][65535];
int main()
{
	int n;
	cin>>n;
	long long left,right,up,down;
	while(n--)
	{
		long long x,y,len;
		cin >> x >> y >> len;
		left = min(x, left);
		right = max(x + len, right);
		up = min(y, up);
		down = max(y + len, down);
		// cout << x + len << endl;
		for(long long  i = x; i < x + len;i++)
			for(long long j = y;j < y + len;j++)
				martex[i][j] = '1';
	}
	long long ans = 0;
	for(long long  i = left; i < right;i++)
		for(long long  j = up;j < down;j++)
		{
			if(martex[i][j] == '1')
				ans++;
		}

	cout << ans << endl;
	return 0;
}
