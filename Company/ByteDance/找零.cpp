#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int money = 1024 - n;
	int dp[1024];
	dp[0] = 0;
	for(int i = 1;i <= money;i++)
	{
		int cost = 50000;
		if(i - 1 >= 0) cost = min(cost,dp[i-1] + 1);
		if(i - 4 >= 0) cost = min(cost,dp[i-4] + 1); 
		if(i - 16 >= 0) cost = min(cost,dp[i-16] + 1); 
		if(i - 64 >= 0) cost = min(cost,dp[i-64] + 1); 
		// printf("dp[%d] = %d\n", i, dp[i]);
		dp[i] = cost;
	}
	cout << dp[money] << endl;
	return 0;
}