#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0;i < n;i++) {
			cin >> nums[i];
		}
		int cnt = 1;
		int i = 0;
		for(;i < n;i++) {
            int nowLevel = nums[i];
            int minDiff = INT_MAX;
            int nextPos = i;
            int j = i+1;
            for(;j <= k && j < n;j++) {
                int diff = nowLevel - nums[j];
                if(diff > 0 && minDiff > diff){
                    minDiff = diff;
                    nextPos = j;
                }
                // cout << j << endl;
            }
            if(minDiff == INT_MAX){

                if(cnt == 1){
                	// cout << "mg " << i << endl;
                    i += k;
                    cnt = 0;
                }else{
                    break;
                }
                
            }else{
                i = j - 1;
            }
		}

		if(i >= n )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}


小易有n根柱子，第i根柱子的高度为hi 从i跳到j