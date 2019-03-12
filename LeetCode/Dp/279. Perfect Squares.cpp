class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        //四平方和原理，任意一个数最多由四个平方数组成。那么这里的答案最多就是4.
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
// 以12为例
// dp[0]=0
// dp[1]=dp[0]+1=1
// dp[2]=dp[1]+1=2
// dp[3]=dp[2]+1=3
// dp[4]=dp[0]+1=1
// dp[5]=dp[4]+1=2
// dp[6]=dp[5]+1=3
// dp[7]=dp[6]+1=4
// dp[8]=dp[4]+1=2
// dp[9]=dp[0]+1=1
// dp[10]=dp[9]+1=2
// dp[11]=dp[10]+1=3
// dp[12]=dp[8]+1=3