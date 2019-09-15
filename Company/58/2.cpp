#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<int> cookies(n, 1);
	for(int i = 0;i < n - 1;i++) {
		// cout << last << endl; 
		if(nums[i+1] > nums[i])
			cookies[i+1] = cookies[i] + 1;

	}

	for(int i = n-1;i > 0;i--) {
		if(nums[i - 1] > nums[i])
			cookies[i-1] = max(cookies[i-1], cookies[i]+1);
	}

	cout << accumulate(cookies.begin(), cookies.end(), 0 ) << endl;
	return 0;
}