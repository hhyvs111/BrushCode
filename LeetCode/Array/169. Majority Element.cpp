class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //求对数，很精妙的解法。如果出现一样的则cnt++，如果有不一样的则减少cnt，当cnt等于0时直接换一个候选值
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res) cnt++;
            else if (cnt > 1) cnt--;
            else res = nums[i];
        }
        return res;

    }
};