class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //最长递增子序列,不是连续递增子序列，那就难咯要用到dp了
        vector<int> dp(nums.size(), 1);
        int res = 0;
        //算法o(N),其中dp[i]表示以nums[i]为结尾的最长递增子串的长度
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = 0; j < i ;j++)
            {
                //每次i都和0到i-1的数比较，如果大就更新dp
                if(nums[i] > nums[j])
                {
                    //没有就是0
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
             res = max(res, dp[i]);
        }
        return res;
    }
};