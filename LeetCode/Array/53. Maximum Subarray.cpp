class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //最大连续子串和，经典的dp
        int nowSum = nums[0];
        int maxSum = nowSum;
        for(int i = 1; i < nums.size();i++)
        {
            //如果加了这个值是大于nums[i]的，那么就加，因为是正向的
            //如果加了这个值比当前的值还要小，那么这个序列是成负向的，直接把标号移动到nums[i]的位置
            nowSum = (nowSum + nums[i])  >= nums[i]? (nowSum + nums[i]) : nums[i];
            
            maxSum = max(maxSum,nowSum);
            
        }
        return maxSum;
    }
};