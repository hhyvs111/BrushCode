class Solution {
public:
    int rob(vector<int>& nums) {
        //这里多了一个条件，就是最后一个和第一个是相连的，那么意思是抢了第一个就不能抢最后一个。
        //根据提示，那么问题就变成1到n-1和2到n的价值选择
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 0; i < nums.size() - 1;i++) {
           int tmp = prev1;
           prev1 = max(prev2 + nums[i], prev1);
           prev2 = tmp;
        }
        int maxNum1 = prev1;
        prev1 = 0, prev2 = 0;
        for (int i = 1; i < nums.size();i++) {
           int tmp = prev1;
           prev1 = max(prev2 + nums[i], prev1);
           prev2 = tmp;
        }
        return maxNum1 > prev1 ? maxNum1 : prev1;
        // vector<int> dp(nums.size() + 1);
        // dp[0] = 0;
        // dp[1] = nums[0];
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        // }
        // return dp[nums.size()];
    }
};