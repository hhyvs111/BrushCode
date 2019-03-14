class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 输入是无序的，需要先进行排序
        sort(nums.begin(), nums.end());
        // 一些“全局变量”的声明
        vector<int> current;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        // 回溯遍历所有方案
        backtracking(ans, nums, current, used);
        return ans;
    }
    void backtracking(vector<vector<int>>& ans, vector<int>& nums, vector<int>& current, vector<bool>& used) {
        // 判断是否已经得出了一组方案
        if (nums.size() == current.size()) {
            ans.push_back(current);
        }
        else {
            // 依次枚举剩下的没有使用的数字
            for (int i = 0; i < nums.size(); i++) if (!used[i]) {
                // 确保在一个位置不会枚举两个相同的数
                if (i == nums.size() - 1 || nums[i] != nums[i + 1] || used[i + 1]) {
                    // 更新状态值
                    current.push_back(nums[i]);
                    used[i] = true;
                    backtracking(ans, nums, current, used);
                    // 回溯
                    used[i] = false;
                    current.pop_back();
                }
            }
        }
    }
};