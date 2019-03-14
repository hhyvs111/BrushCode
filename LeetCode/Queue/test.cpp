#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	auto it = v.end();
	it--;
	cout <<*it<< endl;
	v.insert(v.begin(), 0);
	cout <<*it<< endl;
	return 0;	
}