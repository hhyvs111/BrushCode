class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            //对于[1,1,2]，如果还是采用原先的处理，结果集中肯定会有重复的元素出现，那么怎么处理呢？方法就是只对本层循环中重复元素出现进行调用，而对下一层递归中重复元素跳过递归调用。为了使重复元素相邻，我们首先要对数组排序。接下来就可以使用一行代码对重复情况进行排除：
            if(i == start || candidates[i] != candidates[i - 1])
            {
                combinate.push_back(candidates[i]);
                //这里的是i，因为可以传入自己，上次那个subsets只能传入下一个值，然后还传入了目标值，因为要减去等于0
                combination(candidates, combinate, i + 1, target - candidates[i], res);
                combinate.pop_back();
            }

    }
};