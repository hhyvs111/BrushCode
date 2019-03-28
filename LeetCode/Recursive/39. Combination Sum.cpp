class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //一看又不会做，也是一个组合值，加上后等于这个目标值。
        //又是用回溯法，这种类似的组合可以用这个回溯法。
        //先排序
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combinate;
        combination(candidates, combinate, 0, target, res);
        return res;
    }
    void combination(vector<int>& candidates, vector<int>& combinate, int start, int target, vector<vector<int>>& res)
    {
        //如果为0那么就是成立
        if(!target)
        {
            res.push_back(combinate);
            return;
        }
        for(int i = start; i < candidates.size() && target >= candidates[i]; ++i)
        {
            combinate.push_back(candidates[i]);
            //这里的是i，因为可以传入自己，上次那个subsets只能传入下一个值，然后还传入了目标值，因为要减去等于0
            combination(candidates, combinate, i, target - candidates[i], res);
            combinate.pop_back();
        }
    }
};