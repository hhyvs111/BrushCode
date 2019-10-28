#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin >> str;
	int i = 0, j = str.size() - 1;
	while(i < j){
		// cout << str[i] << " " << str[j] << endl;
		if(str[i] != str[j]){
			cout << "false" << endl;
			return 0;
		}
		i++;
		j--;
	}
	cout << "true" << endl;
	return 0;
}