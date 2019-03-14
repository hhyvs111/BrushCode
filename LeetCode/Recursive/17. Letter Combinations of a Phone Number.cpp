class Solution {
public:

    string strNums[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        //这道题有点像排列组合，那而且是有顺序的。但是要写一个基本的数组放进去。
        vector<string> ans;
        if(digits.empty()) return ans;
        string candidate = "";
        helper(ans, candidate, 0, digits, digits.size());
        return ans;
    }
    //类似一个递归树，每次都和其中一个排列组合，但是如何排列呢？
    //参数详解，start就是当前是第几个数，size是总长度，如果是3个字符那么字符串也是3个。
    void helper(vector<string>& ans, string& candidate,int start,string& digits ,int size)
    {
        if(start == size)
        {
            ans.push_back(candidate);
            return ;
        }
        for(int i = 0; i < strNums[digits[start] - '0'].size(); i++)
        {
            candidate += strNums[digits[start] - '0'][i];
            helper(ans, candidate, start + 1, digits, size);
            //每次传入一个参数后再将其pop出来，比如a，然后b再作为第一个依次递归。
            candidate.pop_back();
        }
        
    }
};