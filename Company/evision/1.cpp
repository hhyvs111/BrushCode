#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	istringstream is(str);
	int in;
	char ch;
	vector<int> nums;
	while(is >> in) {
		nums.push_back(in);
		is >> ch;
	}

	int maxProfit = 0;
	for(int i = 1;i < nums.size();i++) {
		if(nums[i] < nums[i-1])
			maxProfit += nums[i-1] - nums[i];
	}
	cout << maxProfit << endl;
	return 0;
}