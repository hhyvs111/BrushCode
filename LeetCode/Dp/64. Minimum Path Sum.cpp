class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        //经典动态规划题，从原点到grid[i][j]的最短路径为原点到grid[i-1][j] 和grid[i][j-1]的最小值，那么从小到大递推，时间复杂度为O(m * n);
        
        //在边界的时候没有最短路径，路径就是直接相加。
        for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int i = 1; i < n; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
        
        //开始递推
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};