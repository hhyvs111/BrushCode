#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int> (n));
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++)
			cin >> grid[i][j];
	}

	int dp[m][n];
	dp[0][0] = grid[0][0];
	for(int i = 1;i < m;i++)
		dp[i][0] = grid[i][0] + dp[i-1][0];
	for(int i = 1;i < n;i++) {
		dp[0][i] = grid[0][i] + dp[0][i-1];

	}

	for(int i = 1;i < m;i++) {
		for(int j = 1;j < n;j++) {
			//走下或者走左，看哪个是最优的。
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[m-1][n-1] << endl;
	return 0;
}