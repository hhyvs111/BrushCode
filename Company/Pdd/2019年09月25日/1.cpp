#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	long long ans = 0;
	// for(int i = 0;i < m;i++) {
	// 	ans += nums[i] * nums[2 * m - 1 -i];
	// }
	if(m == 1){
		cout << nums[0] * nums[1] << endl;
		return 0;
	}else {
		int i = 0;
		int j = m*2 - 1;
		while(m > 0 && i < j) {
			// cout << ans << endl;
			ans += nums[i++] * nums[j--];
			m--;
		}
		// ans += nums[i] * nums[i+1];
	}

	cout << ans << endl;
	return 0;
}