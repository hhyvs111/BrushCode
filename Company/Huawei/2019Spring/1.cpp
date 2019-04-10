#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0 ;i < n;i++)
    {
        cin >> strs[i];
    }
    multiset<string> ans;
    for(int i = 0;i < n;i++)
    {
        int nowSize = strs[i].size();
        //需要拆分
        if(nowSize > 8){
            int index = 0;
            while(nowSize > 8)
            {
                string now = strs[i].substr(index, 8);
                ans.insert(now);
                index += 8;
                nowSize -= 8;
            }
            string zero = "";
            for(int j = 0;j < 8 - nowSize;j++){
                zero += "0";
            }
            string now = strs[i].substr(index,nowSize);
            ans.insert(now + zero);P
        }
        else{
            string zero = "";
            string now = strs[i].substr(0,nowSize);
            for(int j = 0;j < 8 - nowSize;j++){
                zero += "0";
            }
            ans.insert(now + zero);
        }

    }
    for(auto it = ans.begin(); it != ans.end();it++)
        cout << *it <<  " ";
    return 0;
}