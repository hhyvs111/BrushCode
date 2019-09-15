#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin >> str;
	istringstream is(str);
	int in;
	char ch;
	vector<int> nums;
	while(is >> in) {
		nums.push_back(in);
		is >> ch;
	}

	set<int> s(nums.begin(), nums.end());
	cout << s.size() << endl;
	return 0;
}