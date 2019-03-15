class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 1);
//         int ans = 0;
//         for(int i = 0 ; i < n ;i++)
//         {
//             for(int j = 0; j < i;j++)
//             {
//                 if(nums[j] < nums[i])
//                 {
//                     dp[i] = max(dp[i], dp[j] + 1);
                    
//                 }
//             }
//             ans = max(dp[i], ans);
//         }
//         return ans;
        
        //用二分查找，时间复杂度为nlogn
        vector<int> dp;
        if(nums.size() == 0)
            return 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            int left = 0;
            int right = dp.size();
            //找到dp中第一个不比nums[i]大的数，如果找不到则直接插入到后面
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};