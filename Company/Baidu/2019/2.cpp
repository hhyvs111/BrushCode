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
		


	}
}