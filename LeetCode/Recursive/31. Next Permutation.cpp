class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //意思就是将这个排列转换为字典序更大的，如果已经是更大的那么就转换为最小的。
        //
        int n = nums.size(), i = n - 2, j = n - 1;
        //从右往左找到第一个降序值
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        
        if (i >= 0) {
            //然后再从右往左找到第一个比nums[i]大的值
            while (nums[j] <= nums[i]) --j;
            //交换他们
            swap(nums[i], nums[j]);
        }
        //再倒序，这样就是保证字典序比原来的大1。
        //如果没找到那么就是0，原地逆置数组
        reverse(nums.begin() + i + 1, nums.end());
    }
};