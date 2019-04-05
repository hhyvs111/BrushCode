#include<bits/stdc++.h>
using namespace std;

int charge(vector<int>& coinsValues, int n)
{
        vector<vector<int>> c(coinsValues.size() + 1, vector<int>(n + 1));
        // 初始化边界条件
        for(int i = 0; i <= coinsValues.size(); i++){
            c[i][0] = 0;
        }
        for(int i = 0; i <= n; i++){
            c[0][i] = INT_MAX;
        }
        int maxCoins = -1;
        for(int i = 1; i<=coinsValues.size(); i++){//i表示参加找零的硬币的种类1~i种硬币
            for(int j = 1; j <= n; j++){//j表示需要找零的钱数
                if(j < coinsValues[i-1]){
                    c[i][j] = c[i - 1][j];
                    continue;
                }

                //每个问题的选择数目---选其中较小的
                if(c[i - 1][j] < (c[i][j - coinsValues[i-1]] +1)) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - coinsValues[i-1]] +1;
                }

            }

        }
        int minCoin = INT_MAX;
        for(int j = 1; j <= n;j++)
            {
                minCoin = min(c[coinsValues.size()][j], minCoin);
                 // cout << j << " " << c[coinsValues.size()][j] << endl;
                maxCoins = max(c[coinsValues.size()][j], maxCoins);
            }

        // return c[coinsValues.size()][n];
        return maxCoins + minCoin ;

}
int main()
{
    //类似于上台阶，看能有多少种方法组成以上面值，最少的那一部分。
    int m,n;
    cin >> m >> n;
    vector<int> coins;
    for(int i = 0; i < n;i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    cout << charge(coins, m);
    return 0;
}
