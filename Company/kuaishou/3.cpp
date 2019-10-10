#include<bits/stdc++.h>
using  namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	long long sum = 0;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		sum+= nums[i];
	}
	//背包问题，直接求解即可。
	sort(nums.begin(), nums.end());
	vector<vector<int>> f(n + 1, vector<int> (sum/2 + 1));
	for(int i = 0;i < n;i++) {
		for(int j = 1;j <= sum/2;j++) {
			f[i+1][j] = f[i][j];
			if(nums[i] <= j && f[i][j - nums[i]] + nums[i] > f[i][j])
				f[i+1][j] = f[i][j-nums[i]] + nums[i];
		}
	}
	cout << sum - 2 * f[n][sum/2] << endl;

	return 0;
}