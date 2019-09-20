#include<bits/stdc++.h>
using namespace std;


int main() {
	int k;
	cin >> k;
	vector<int> nums{0,0,0};
	int num;
	// vector<int> nums;
	// while(cin >> num) {
	// 	nums.push_back(num);
	// }

	sort(nums.begin(), nums.end());

	int n = nums.size();
	//最大差值
	int res = nums[n - 1] - nums[0];

	for(int i = 0;i < nums.size();i++) {
		res = min(res, max(nums[n - 1],  nums[i] + 2 * k) - min(nums[i+1], nums[0] + 2*k));
	}
	cout << res << endl;
	return 0;


}