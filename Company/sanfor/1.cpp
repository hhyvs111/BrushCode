#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> nums(n); 
	for(int i = 0;i < n;i++){
		cin >> nums[i];
	}

	int x = nums[0];
	int ans = 1;
	if(x > 0) {
		for(int i = 0;i < n;i++) {
			if(nums[i] < 0 && -nums[i] > x)
				ans++;
		}
		if(ans != 1) {
			for(int i = 0;i < n;i++){
				if(nums[i] > 0 && nums[i] < x)
					ans++;
			}
		}
	}else {
		for(int i = 0;i < n;i++) {
			if(nums[i] > 0 && nums[i] < -x)
				ans++;
		}
		if(ans != 1) {
			for(int i = 0;i < n;i++){
				if(nums[i] < 0 && nums[i] < x)
					ans++;
			}
		}
	}
	cout << n - ans << endl;
	return 0;
}