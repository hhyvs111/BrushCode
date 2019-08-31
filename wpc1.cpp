#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;
	while(n--) {
		int k, b, p;
		cin >> k >> b;
		for(int i = 0; i < k; i++) {
			cin >> p;
			int num = p + b;
			if (num % 7 == 0) {
				ans = 1;
			}

		}

		if (ans == 1) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		ans = 0;

	}
	return 0;
}