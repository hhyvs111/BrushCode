#include<bits/stdc++.h>
using namespace std;

string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs(vector<string>& allRes, string& str, string s, int begin) {
	if(begin == str.size()){
		allRes.push_back(s);
		return;
	}
	string tmp = dict[str[begin] - '2'];
	for(int i = 0;i < tmp.size();i++){
		s.push_back(tmp[i]);
		dfs(allRes, str, s, begin + 1);
		s.pop_back();
	}

}
int main() {
	string str;
	cin >> str;

	vector<string> allRes;
	string s = "";

	dfs(allRes, str, s, 0);
	cout << "[";
	sort(allRes.begin(), allRes.end());
	for(int i = 0;i < allRes.size() - 1;i++) {
		cout << allRes[i] <<", ";
	}
	cout << allRes[allRes.size()-1] << "]" <<endl;
	return 0;

}