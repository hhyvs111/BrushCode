#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	unordered_map<int,int> mp;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		mp[nums[i]]++;
	}

	int k;
	while(m--) {
		cin >> k;

		cout << mp[k] << endl;
	}
	return 0;
}