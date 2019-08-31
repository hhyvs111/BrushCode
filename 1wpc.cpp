#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;
	while(n--) {
		int number;
		cin >> number;
		string str;
		string ans= "";
		for(int i = 0; i < number;i++) {
			cin >> str;
			ans += toupper(str[0]);
		}
		cout << ans << endl;

	}
	return 0;
}