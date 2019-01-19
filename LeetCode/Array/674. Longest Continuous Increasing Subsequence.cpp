class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        else if(nums.size() == 1)
            return 1;
        int maxIncSize = 0;
        int nowIncSize = 1;
        
        for(int i = 0; i < nums.size() - 1;i++)
        {
            if(nums[i] < nums[i+1])
                nowIncSize++;
            else 
                nowIncSize = 1;
            maxIncSize = max(maxIncSize, nowIncSize);
        }
        return maxIncSize;
    }
};