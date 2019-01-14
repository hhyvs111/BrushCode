class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0;i < nums.size(); i+=2)
        {
            ans += min(nums[i], nums[i+1]);
        }
        return ans;
    }
};

//看了提示才做出来的，先排序，然后取小的。