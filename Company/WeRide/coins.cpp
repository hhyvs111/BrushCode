#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> coins;
    string s;
    getline(cin, s);
    istringstream is(s);
    int in;
    char ch;
    while( is >> in){
        coins.push_back(in);
        is >> ch;
    }
    // for(int i = 0;i < coins.size();i++){
    //     cout << coins[i] << endl;
    // }
    long long m;
    cin >> m;
    sort(coins.begin(), coins.end());
    //每一个元素都初始化为最大值
    vector<int> dp(m + 1, m + 1);
    dp[0] = 0;
    for(long long i = 1; i <= m;i++)
    {
        for(int j = 0;j < coins.size();j++){
            if(i - coins[j] >= 0)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
        
    }
    int ans = dp[m] > m ? -1 : dp[m];
    cout << ans << endl;
    return 0;
}