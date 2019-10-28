#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int>& nums);
int main(){
	vector<int> nums{1,3,4,5,9,2,3,100};
	vector<int> ans = func(nums);

	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << " ";
	}
	return 0;
}

vector<int> func(vector<int>& nums){
	vector<int> ans;
	vector<int> minNums(nums.size());
	minNums[nums.size() - 1] = nums[nums.size() - 1];
	for(int i = nums.size() - 2;i >= 0;i--){
		if(nums[i] > minNums[i+1])
			minNums[i] = minNums[i+1];
		else
			minNums[i] = nums[i];
	}
	int maxValue = INT_MIN;
	for(int i = 0;i < nums.size();i++){
		maxValue = max(maxValue, nums[i]);

		if(nums[i] >= maxValue && nums[i] <= minNums[i])
			ans.push_back(nums[i]);

	}
	return ans;
}