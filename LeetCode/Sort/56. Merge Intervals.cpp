/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    //这个算法有点牛逼啊
    vector<Interval> merge(vector<Interval>& ins) {
        if (ins.empty()) return vector<Interval>{};
        vector<Interval> res;
        //这个c++11的特性用的是真的强啊，以后我也要这样用了。
        sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
        //先push第一个进去
        res.push_back(ins[0]);
        for (int i = 1; i < ins.size(); i++) {
            //如果下一个的开头比res里最后一个的尾还大，说明是空区间直接push
            if (res.back().end < ins[i].start) res.push_back(ins[i]);
            else
                //如果小于back的end，那么看一下哪个的end大，然后选择大的那个end，太牛逼了！
                res.back().end = max(res.back().end, ins[i].end);
        }
        return res;
    }
    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        //对左区间进行排序
        vector<Interval> ans;
        if(intervals.size() == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval first = intervals[0];
        for(int i = 0 ; i < intervals.size();i++)
        {
            Interval second = intervals[i];
            if(first.end >= second.start)
            {
                first.end = second.end > first.end ? second.end : first.end;
                if(i == intervals.size() - 1)
                    ans.push_back(first);
            }
            else
            {
                ans.push_back(first);
                first = second;
                if(i == intervals.size() - 1)
                    ans.push_back(first);
            }
        }
        return ans;
    }
    

};

