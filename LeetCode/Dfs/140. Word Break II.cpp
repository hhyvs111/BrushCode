class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }
    //这种类似的肯定是要用到递归的，
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        //mem记忆，如果有则直接返回
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        //当前结果
        vector<string> res;
        //遍历wordDict
        for (string word : wordDict) {
            //如果不是该单词直接跳过
            if (s.substr(0, word.size()) != word) continue;
            //如果找到了，那么递归求解剩下的,这里的substr只有一个参数默认均表示从word.size()位置开始到结尾的子字符串
            vector<string> rem = helper(s.substr(word.size()), wordDict, m);
            for (string str : rem) {
                //给其加空格，如果是str是空了，代表是末尾了。
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};