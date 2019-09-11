#include<bits/stdc++.h>
using namespace std;


//这个
vector<string> split(string s, char delim) {
	vector<string> v;
	stringstream stringstream1(s);
	string tmp;
	//以delim为截止
	while(getline(stringstream1, tmp, delim)){
		v.push_back(tmp);
	}
	return v;
}
int main(){
	char pairs;
	char keyPairs;
	string str;
	cin >> pairs >> keyPairs >> str;

	vector<string> keyValues = split(str, pairs);
	vector<string> key;
	vector<string> values;

	for(string tmp : keyValues) {
		vector<string> v = split(tmp, keyPairs);
		if(v.size() != 2)
			continue;

		key.push_back(v[0]);
		values.push_back(v[1]);
	}

	cout << key.size() << endl;
	for(int i = 0;i < key.size();i++) {
		cout << key[i] << " " << values[i] << endl;
	}
	return 0;
}