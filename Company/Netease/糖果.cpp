//最多存在一块不同的，那么就是sort一下，然后看是否只有两种。
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(char a, char b)
{
    return a < b;
}
int main()
{
    string str;
    while(cin >> str)
    {
        sort(str.begin(), str.end());
        char beg = str[0];
        int cnt = 0;
        int ans = 0;
        cout << str << endl;
        for(auto c : str)
        {
            cout << c << " " << endl;
            if(c != beg)
            {
                cnt++;
                beg = c;
            }
        }
        if(cnt < 2)
            ans++;
        reverse(str.begin(), str.end());
        beg = str[0];
        cnt = 0;
        for(auto c : str)
        {
            if(c != beg)
            {
                cnt++;
                beg = c;
            }
        }
        if(cnt < 2)
            ans++;
        cout << ans;
            
    }
    return 0;
}