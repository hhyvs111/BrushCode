#include<bits/stdc++.h>
using namespace std;
char vb[26];
void dfs(int index, string& str, string now, vector<string>& ans) {
	if(index == str.size()){
		ans.push_back(now);
		return;
	}
	int value = 0;
	int two = 2;
	while(two-- && index < str.size()) {
		value *= 10;
		value += str[index] - '0';
		if(value > 26)
			break;
		// cout << value << endl;
		now += vb[value - 1];
		// cout << "1 " << now << endl;
		dfs(++index, str, now, ans);
		now = now.substr(0, now.size() - 1);
	}
}


int main(){
	for(int i = 0;i < 26;i++) {
		vb[i] = 'A' + i;
		// cout << vb[i] << endl;
	}
	string str;
	cin >> str;
	vector<string> ans;
	dfs(0, str, "", ans);
	sort(ans.begin(), ans.end());
	for(int i = 0;i < ans.size();i++) {
		cout << ans[i] << endl;
	}
	return 0;

}

