class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //简单来说就是在这个s里找到包含p的组合的字母序列，看起来就是很难啊！做都不会做
        //有点像是kmp算法？但是效率不是很高了。如果用看毛片的话
        //我寻思这个和空格匹配也没什么关系啊，好像没什么鸟用
        if(s.empty()) return {};
        vector<int> ans;
        //用两个数组保存值，每次比较p长度的字符数组，如果数组相等的话就是anagrams
        vector<int> s1(256,0);
        vector<int> p1(256,0);
        for(int i = 0;i < p.size();i++)
        {
            s1[s[i]]++;
            p1[p[i]]++;
        }
        if(s1 == p1) ans.push_back(0);
        for(int i = p.size(); i < s.size(); i++)
        {
            //先后移动一位，将对应的值存入s1
            s1[s[i]]++;
            //删除前面一位对应的值, 这里对应的是p.size前一位
            s1[s[i - p.size()]]--;
            if(s1 == p1) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};