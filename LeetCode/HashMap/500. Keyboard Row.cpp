class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        //看到较好的方法，定义三个set，如果有字符出现在两个set以上的返回false！
        
        //返回能用一行字符输出的值
        //建立一个map，他们的关键字都是1，2，3.
        unordered_map<char, int> charMap;
        //处理方式有点sb
        charMap['q'] = 1;
        charMap['w'] = 1;
        charMap['e'] = 1;
        charMap['r'] = 1;
        charMap['t'] = 1;
        charMap['y'] = 1;
        charMap['u'] = 1;
        charMap['i'] = 1;
        charMap['o'] = 1;
        charMap['p'] = 1;
        charMap['a'] = 2;
        charMap['s'] = 2;
        charMap['d'] = 2;
        charMap['f'] = 2;
        charMap['g'] = 2;
        charMap['h'] = 2;
        charMap['j'] = 2;
        charMap['k'] = 2;
        charMap['l'] = 2;
        charMap['z'] = 3;
        charMap['x'] = 3;
        charMap['c'] = 3;
        charMap['v'] = 3;
        charMap['b'] = 3;
        charMap['n'] = 3;
        charMap['m'] = 3;
        vector<string> ans;
        for(string str : words)
        {
            int begin = charMap[tolower(str[0])];
            bool isOneRow = true;
            for(char c : str)
            {
                if(charMap[tolower(c)] != begin)
                {
                    isOneRow = false;
                    break;
                }

            }
            if(isOneRow)
                ans.push_back(str);
        }
        return ans;
        
    }
};