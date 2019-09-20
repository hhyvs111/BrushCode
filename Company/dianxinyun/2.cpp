#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int x = str.find(';');
    int len = str.size();
    string str1 = str.substr(0, x);
    string str2 = str.substr(x+1, len - x);

    if(str1.size() != str2.size()){
    	cout << "False" << endl;
    	return 0;
    }

    set<char> st1(str1.begin(), str1.end());
    set<char> st2(str2.begin(), str2.end());

    if(st1.size() != st2.size()) 
    	cout << "False" << endl;
    else
    	cout << "True" << endl;
    return 0;
}