#include"bits/stdc++.h"

using namespace std;

int main()
{
    string str;
    cin >> str;
    int index = str.size();
    stack<char> sta;
    stack<string> tmp;
    string tmpstr = "";
    string pre = "";
    for(int i = 0;i<index;i++)
    {
        if(str[i] == '(') {

            if(!sta.empty()) {
                // cout << tmpstr << endl;
                tmp.push(tmpstr);
                tmpstr = "";
            }else {
                pre += tmpstr;
                tmpstr = "";
            }
            sta.push(str[i]);
            
        }
        else if(str[i] == ')')
        {
            if(sta.empty()){
                cout << "" << endl;
                return 0;
            }else {
                sta.pop();
                reverse(tmpstr.begin(), tmpstr.end());
                if(!tmp.empty()) {
                    tmpstr = tmp.top() + tmpstr;
                    tmp.pop();
                }    

            }

            
            
        }else {
            tmpstr += str[i];
        }

    }
    // cout << pre << endl;
    cout << pre+tmpstr << endl;

    return 0;
}