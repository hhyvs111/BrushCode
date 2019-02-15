class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};
//递归处理，主要是后面的这个pop比较精髓，比如1，2，3。这个时候要填入这个1，2和1，3这个子集。本来是有1，1这个子集的，但是后面的pop删掉了1，所以这个就没了。
//自己完全想不到嘛，真的难。这个都是些啥玩意