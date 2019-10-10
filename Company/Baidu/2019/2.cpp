#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		vector<int> nums(n);
		int sum  = 0;
		for(int i = 0;i < n;i++){

			cin >> nums[i];
			sum += nums[i];
		}
		if(sum == 0){
			cout << "woman" << endl;
		}
		int ans = 0; //0为man，1位women
		while(sum--) {
			sort(nums.begin(), nums.end());
			if(nums)
		}
	}
}