#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> nums(n, 0);
	int cnt = 0;
	int l = 0, r = 0;
	while(m--){
		int left, right;
		cin >> left >> right;
		for(int i = left; i <= right;i++) {
			if(nums[i] == 0){
				nums[i] = 1;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}