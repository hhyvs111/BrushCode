class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //相同字母的为一组，还是用hash？
        if(strs.empty()) return {};
        
        map<vector<int>, vector<int>> mapIndex;
        int cnt = 0;
        //用一个map存相同字符的位置，key为nums数组
        for(auto s : strs)
        {
            vector<int> nums (26, 0);
            for(char c : s)
            {
                nums[c - 'a']++;
            }
            //相同的vector，把他们的位置放入map
            mapIndex[nums].push_back(cnt++);
        }
        vector<vector<string>> ans;
        
        for(auto it = mapIndex.begin(); it != mapIndex.end();it++)
        {
            vector<string> subAns;
            //获取map在strs对应的位置
            for(int i = 0 ; i < it->second.size(); i++)
            {
                subAns.push_back(strs[it->second[i]]);
            }
            ans.push_back(subAns);
        }
        return ans;
            
    }
};

//先将str排序一下，用局部变量排序，不能改变原来的值。然后插入到unordered_map里去
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //string为排序好的值，后面的vector为这个对应的anagrams
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            //对string里的char进行字典序排序
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};