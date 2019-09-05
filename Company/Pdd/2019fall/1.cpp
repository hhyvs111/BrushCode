#include<bits/stdc++.h>

using namespace std;



bool help(int a, int b) {
	if(a%2  == b%2){
		if (a > b)
			return true;
		else 
			return false;
	}
	else if(a%2 == 0 && b%2 == 1)
		return true;
	else if(a%2 == 1 && b%2 == 0)
		return false;

}


int main(){
	string str;
	cin >> str;
	int strSize = str.size();
	vector<int> v;
	istringstream is(str);
	int in;
	char ch;
	while (is >> in){
		// cout << in << endl;
		v.push_back(in);
		is >> ch;
	}

	// for(int i = 0;i < v.size();i++) {
	// 	cout << v[i] << endl;
	// }

	sort(v.begin(), v.end() - 1, help);
	int i = 0;
	for(;i < v[v.size() - 1] - 1; i++) {
		cout << v[i]  << ",";
	}
	cout << v[i] << endl;


}