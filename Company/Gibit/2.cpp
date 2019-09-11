#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
const int INF = 0x3f3f3f3f;


int dp[maxn][15];
int mp[15][15];
int dig[15];
int sta[maxn][15];

int main() {

	dig[0] = 1;
	for(int i = 1; i <= 10;i++) {
		dig[i] = dig[i-1]*3;
	}

	for(int i = 0;i < dig[10];i++) {
		int x = i;
		for(int j = 0;j < 10;j++) {
			sta[i][j] = x%3;
			x /= 3;
		}
	}
	int n, m;
	cin >> n >> m;
	memset(mp, INF, sizeof(mp));
	for(int i = 1;i <= m;i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		--u,--v;
		mp[u][v] = mp[v][u] = min(mp[u][v], cost);
	}
	memset(dp, INF, sizeof(dp));
	for(int i = 0;i < n;i++) 
		dp[dig[i]][i] = 0;

	for(int i = 0; i < dig[n];i++) {
		for(int j = 0;j < n;j++) {
			if(dp[i][j] == INF)
				continue;
			for(int k = 0;k < n;k++) {
				if(sta[i][k] >= 2)
					continue;
				dp[i+dig[k]][k] = min(dp[i+dig[k]][k], dp[i][j] + mp[j][k]);
			}
		}
	}

	int ans = INF;
	for(int i = 0; i < dig[n];i++) {
		bool flag = 1;
		for(int j = 0;j < n;j++) {
			if(!sta[i][j]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			for(int j = 0; j < n;j++) {
				ans = min(ans, dp[i][j]);
			}
		}
	}
	if(ans < INF) 
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}