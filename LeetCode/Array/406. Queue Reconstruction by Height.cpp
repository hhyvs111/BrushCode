class Solution {
public:
    static bool cmp(pair<int, int> t1, pair<int, int> t2)
    {
        return t1.first > t2.first || (t1.first == t2.first && t1.second < t2.second);
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //lamba写法
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        //这个pair的意思是<高度、前面比我高的人的个数>这里相等高度也算。给你一些pair，但是不是规律的，然后重建这个队列
        //根据h排序
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> res;
        //排完序后将其插入到正确位置，如果有0则会向后移。
        for (auto& p : people) 
        {
            res.insert(res.begin() + p.second, p);
            cout << p.second << endl;
        }
            
        return res;
    }
};
// 这道题给了我们一个队列，队列中的每个元素是一个pair，
// 分别为身高和前面身高不低于当前身高的人的个数，让我们重新排列队列，使得每个pair的第二个参数都满足题意。
// 首先我们来看一种超级简洁的方法，不得不膜拜想出这种解法的大神。首先我们给队列先排个序，按照身高高的排前面，如果身高相同，则第二个数小的排前面。
// 然后我们新建一个空的数组，遍历之前排好序的数组，然后根据每个元素的第二个数字，将其插入到res数组中对应的位置，参见代码如下：