class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        //优先队列，默认是最大堆
        priority_queue<pair<int, int>> q;
        vector<int> res;
        //可以这样直接插入，学习一下
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            //将堆顶输出
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};