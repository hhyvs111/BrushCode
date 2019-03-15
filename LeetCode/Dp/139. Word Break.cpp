class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //就是给你一串字符串，看是否能拼出s，这个题也估计是用回溯法做,但是如何重复呢？看题目相关性说是用这个动态规划，那么就不能用回溯法了。
        if(wordDict.size() == 0) return false;
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        //利用一下substr
        //每个子串是否能在dict里找到？
        vector<bool> dp(s.size() + 1);
        //是因为我们要handle空串的情况，我们初始化dp[0]为true
        dp[0] = true;
        for(int i = 0;i < dp.size();i++)
        {
            for(int j = 0; j < i ;j++)
            {
                //我们用j把[0, i)范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是dp[j]，范围 [j, i) 就是s.substr(j, i-j)，其中dp[j]是之前的状态，我们已经算出来了，可以直接取，只需要在字典中查找s.substr(j, i-j)是否存在了，如果二者均为true，将dp[i]赋为true，并且break掉
                if(dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
               
            }
        }
        return dp.back();
        
    }
    
};