#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	vector<int> nums;
	int i  = 0;
	int len = str.size();
	while(i < len) {
		if(str[i] == '-') {
			int num = 0;
			i++;
			int p = 1;
			while(str[i] >= '0' && str[i] <= '9'){
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			nums.push_back(0 - num);
		}
		if(str[i] >='0' && str[i] <='9') {
			int num = 0;
			int p = 1;
			while(str[i] >= '0' && str[i] <= '9'){
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			nums.push_back(num);
		} else {
			i++;
		}
	}
	// for(int i = 0;i < nums.size();i++) {
	// 	cout << nums[i] << endl;
	// }

	int maxNum = nums[0];
	int nowNum = nums[0];
	for(int i = 1;i < nums.size();i++) {
		if(nowNum + nums[i] < nums[i]) {
			nowNum = nums[i];
		}else {
			nowNum += nums[i];
		}
		maxNum = max(maxNum, nowNum);

	}
	cout << maxNum << endl;
	return 0;
}