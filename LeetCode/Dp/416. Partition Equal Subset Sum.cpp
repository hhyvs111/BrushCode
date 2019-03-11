// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         //这个题就是将数组一分为二，看值是否相等，怎么又是有点像这个回溯法？
//         //先求数组的总值，然后看是否有子数组的和相加为总值的一半，有的话代表可以partition，好像不是用这个回溯法啊。
//         //不行啊，如果sum是奇数，那么肯定是不对的。所以还是要比较
//         //那么每次都调用这个accumulate?
//         //暴力感觉好像可以，数组不是很大，但是不符合面试要求吧。
//         //还是可以用回溯法的，设定一个bool量
//         sort(nums.begin(), nums.end());
//         for(auto it = nums.begin(); it != nums.end();it++)
//         {
//             if(accumulate(nums.begin(), it, 0) == accumulate(it, nums.end(), 0))
//                 return true;
//         }
//         return false;
//     }
// };
//动态规划方法，哎我还是太菜了，完全是不会的，心态爆炸啊大兄弟。难受的很了！十分难受
//就是判断是否dp[i - num]为true,如果为true那么我也搞不懂了，太菜了！
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};