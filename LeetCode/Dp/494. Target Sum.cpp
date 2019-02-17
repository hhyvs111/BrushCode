class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //这个有点像之前的子集，也是很多情况
        //比如一个加号的，一个减号的各种排列组合
        //其实就是将符号到处排列，这样好像有点浪费时间。
        //用递归做，类似于二叉树，比如1，2，3，4。1有两种选择，加2和减2，然后依次递推
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    //学会使用递归
    void helper(vector<int>& nums, int S, int start, int& res) {
        //当已经到边界的时候，看是否等于0.
        if (start >= nums.size()) {
            if (S == 0) ++res;
            return;
        }
        //减就是加
        helper(nums, S - nums[start], start + 1, res);
        helper(nums, S + nums[start], start + 1, res);
    }
};

//这个方法很牛逼，将问题简化为在nums里找几个数的和等于s，找这样的组合
//dp[i]表示子集合元素之和等于当前目标值的方案个数, 当前目标值等于9减去当前元素值
//说是01背包问题，到时候再回来看看吧！

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};