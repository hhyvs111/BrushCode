#include<bits/stdc++.h>
using namespace std;
int main() {

	//这个题要处理一下这个输入
	int value;
	string str;
	cin >> value >> str;
	int strSize = str.size();
	vector<int> v;
	str = str.substr(1, strSize - 1);
	istringstream is(str);
	int in;
	char ch;
	while (is >> in){
		// cout << in << endl;
		v.push_back(in);
		is >> ch;
	}
	int coinKinds = v.size();

	vector<vector<int>> dp(coinKinds + 1, vector<int>(value + 1, 0));
	

	for(int i = 0;i <= coinKinds;i++) {
		dp[i][0] = 1;
	}

	for(int i = 1;i <= coinKinds;i++) {
		for(int j = 1; j <= value ; j++) {
			dp[i][j] = 0;

			for(int k = 0; k <= j/v[i-1]; ++k) {
				dp[i][j] += dp[i-1][j - k * v[i-1]];
			}
		
		}
	}

	cout << dp[coinKinds][value] << endl;
	return 0;

}