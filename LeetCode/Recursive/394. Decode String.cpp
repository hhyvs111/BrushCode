class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            //如果是字符则直接加
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                //如果是数字则计算长度，要考虑不小于10的数
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                //这里一般就是括号
                i++; // '['
                //直接省略括号，然后将这个代入递归操作
                string t = decodeString(s, i);
                i++; // ']'
                //返回的t肯定是要加多少次的
                while (n-- > 0)
                    res += t;
            }
        }
        //这里也是返回每一次递归所得到的字符
        return res;
    }
    
    //调用
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};


class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            //每次遇到[的时候将剩余字符传入，子问题递归
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
                //当遇到了 ] 时则代表结束子问题的递归了
            } else if (cur == ']') {
                return word;
            } else {    // Normal characters
                word += cur;
            }
        }
        return word;
    }
};