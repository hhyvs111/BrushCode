class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //必须是正方形，不能是长方形。dfs？统计这个垂直多少，然后竖直多少。
        //完全不会啊，难受。又是尼玛动态规划，这个怎么推呢？
        //用暴力法也可以，但是时间复杂度太高了
        //dp的思想就是从小到大，然后dp[i][j]就是一个正方形的右下角的点，然后其代表的值就是最大的矩形。那么最大的矩形通过上一个矩形推出，如果它的左上也就是对象线是1，而且方便和左边也是1，那么就取其最小值。
        //那么如果出现题目中的长方形那样的看看是多少，因为只能看中间那个值，中间的值是1，那么该正方形也是1，然后加1最大值也是2。但是如果是9个1组成的就能在右下角判断是3了，因为其左上、左边和上边都是2，最小也是2，然后加1就是3.
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0 ; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                //边界情况肯定是1，
                if(i == 0 || j == 0 ) dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                {
                    //核心递推式，直接看左上、左边和上方的最小值，因为要是正方形，然后其值加1。如果左边只是1，说明没有构成正方体，那么还是2.
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};