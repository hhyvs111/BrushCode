#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    vector<int> v;
    getline(cin, s);
    if(s == "None")
    {
    	cout << "True" << endl;
    	return 0;
    }
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
    		cout << inter << endl;
         v.push_back(inter);
         is >> ch;
    }
    for(int i = 0;i < v.size() / 2;i++)
    {
    	if(v[i] < v[2*i + 1] || v[i] > v[2*i + 2])
    		{
    			cout << "False" << endl;
    			return 0;
    		}
    }
    cout << "True" << endl;
    return 0;
}