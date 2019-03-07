class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        //计算有多少种方法到达终点。要不能重复的只能下和右
        //还是dp，到达m,n的方法为到达 (m-1, n)加上 (m, n-1)的方法。
        int dp[m][n];
        dp[0][0] = 0;
        
        for (int i = 1; i < m; ++i) dp[i][0] = 1 ;
        for (int i = 1; i < n; ++i) dp[0][i] = 1 ;
        
        //开始递推
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
        
    }
};