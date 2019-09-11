#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		vector<int> num;
		while(x > 0) {
			num.push_back(x%2);
			x /= 2;
		}

		int left = 0, right = num.size()-1;
		bool ans = true;
		while(left < right){
			if(num[left++] != num[right--]){
				ans = false;
				break;
			}

		}
		if(ans)
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}