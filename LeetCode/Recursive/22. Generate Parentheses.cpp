#include<string>
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //这题也能用回溯法，尼玛这个回溯法是真的牛批。
        //感觉只要是排列组合就能用回溯法，这个要记住了。然后回溯里写好这个条件，难的就是这个条件的处理上了！
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
        
        //这里主要是用open和close，也就是配对，只要是open<max，那么代表还可以添加(，如果close比open小，意味着(比)多，此时要加一个)
    void backTrack(vector<std::string>& ans, string cur, int open, int close, int max)
    {
        if(cur.size() == max * 2)
        {
            ans.push_back(cur);
            return;
        }

        if(open < max)
        {
            backTrack(ans, cur + "(", open + 1, close, max);
        }
        if(close < open)
        {
            backTrack(ans, cur + ")", open, close + 1, max);
        }
    }
};