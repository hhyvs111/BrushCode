#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word1;
    string word2;
    cin>>word1>>word2;
    int n1 = word1.size();
    int n2 = word2.size();
    vector<int> dp(n1 + 1, 0);
    for(int i = 0; i <= n1; ++i)
        dp[i] = i;
    for(int j = 1; j <= n2; ++j)
    {
        int prev = dp[0];
        dp[0] = j;
        for(int i = 1; i <= n1; ++i)
        {
            int temp = dp[i];
            if(word1[i - 1] == word2[j - 1])
                dp[i] = prev;
            else
                dp[i] = 1 + min(prev, min(dp[i], dp[i - 1]));
            prev = temp;
        }
    }
    cout<<dp[n1]<<endl;
    return 0;
}