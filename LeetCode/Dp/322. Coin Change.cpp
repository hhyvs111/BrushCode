class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //给硬币组合，求最少的能够组成硬币的个数，如果不能组成则返回-1
        //我感觉是否是贪心法？还是说递推？估计是要用递归吧？
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        //求硬币最小个数
        for(int i = 1; i <= amount;i++){
            for(int j = 0; j < coins.size();j++){
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};