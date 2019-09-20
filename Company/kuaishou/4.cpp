#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<map<int,int>> m(n);
	sort(nums.begin(), nums.end());
	int res = 2;
	for(int i = 0;i < nums.size();i++) {
		for(int j = 0;j < i;j++) {
			int dif = nums[i] - nums[j];
			if(m[j][dif]) {
				m[i][dif] = m[j][dif] + 1;
			}
			else {
				m[i][dif] = 2;
			}
			res = max(m[i][dif], res);
		}
	}
	cout << res << endl;
	return 0;
}