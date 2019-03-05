class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};
//相同任务就是一个任务对。

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //两个相同的任务必须间隔n，还是读题有问题啊
        //最快的方法就是先把任务次数最大的给做了
        if(n == 0) return tasks.size();
        map<char,int> mapTask;
        for(char c : tasks)
        {
            mapTask[c]++;
        }
        int cnt = 0;
        int times = 0;
        for(auto it = mapTask.begin(); !mapTask.empty();)
        {
            cout << it->first << endl;
            cout << it->second << endl;
            if(it->second != 0 && times == n)
            {
                cnt++;
                times++;
                it->second--;
                if(it->second == 0)
                    mapTask.erase(it++);
                else
                    it++;
                // cout << it->first << endl;

            }
            //进入休息时间
            if(times == n || it == mapTask.end())
            {
                times = 0;
                it = mapTask.begin();
                if(!mapTask.empty())
                    cnt++;
            }
        }
        return cnt;
    }
};