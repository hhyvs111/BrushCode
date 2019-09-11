#include<bits/stdc++.h>
using namespace std;
int main(){
	string w1, w2;
	cin >> w1;
	cin >> w2;
	int m = w1.size();
	int n = w2.size();

	vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

	for(int i = 0;i < m+1;i++) 
		dp[i][0] = i;
	for(int i = 0;i < n+1;i++)
		dp[0][i] = i;
	
	for(int i = 1;i < m+1;i++) {
		for(int j = 1;j < n+1;j++) {
			if(w1[i-1] == w2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));

		}
	} 
	cout << dp[m][n] << endl;
	return 0;
}