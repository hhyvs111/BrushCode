#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for(int i = 0;i < n;i++) {
		cin >> num[i];
	}
	vector<int> cnt(n, -1);
	int maxBot = -1;
	for(int i = n - 1;i >= 0;i--) {
		for(int j = i - 1;j >=0;j--) {
			if(num[i] - num[j] <= 0) {
				cnt[j]++;
				// cout << j << endl;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n;i++) {
		if(maxBot < cnt[i]) {
			ans = i;
			maxBot = cnt[i];
		}

	}
	int res = maxBot == -1?0:num[ans];
	cout << res << endl;
	return 0;

}