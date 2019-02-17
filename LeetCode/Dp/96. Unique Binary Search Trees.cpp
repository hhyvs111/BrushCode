class Solution {
public:
    int numTrees(int n) {
        //又是用dp，但是自己完全不会啊。主要是自己找一个规律，找到就能写出状态转移方程。
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        //
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
