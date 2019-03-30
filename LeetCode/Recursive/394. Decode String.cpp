#include<bits/stdc++.h>
using namespace std;
string decodeString(string s);
int main()
{
    string s;
    while(cin >> s)
    {
        string ans = decodeString(s);
        cout << ans;
    }
}

string decodeString(string s) {
        string res = "", t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                //将数字放入数字栈
                s_num.push(cnt);
                s_str.push(t);
                //清空字符串t和清零cnt
                cnt = 0; t.clear();
            } else if (s[i] == ']') {
                //遇到右括号说明字符串结束了
                int k = s_num.top(); s_num.pop();
                //这里将字符串加k次
                for (int j = 0; j < k; ++j) s_str.top() += t;
                //再取一次当前栈顶元素就是刚刚已经加了k次的，然后弹出栈顶。因为要注意嵌套的情况。
                t = s_str.top(); s_str.pop();
                cout << t << endl;
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }


// class Solution {
// public:
//     string decodeString(const string& s, int& i) {
//         string res;
        
//         while (i < s.length() && s[i] != ']') {
//             //如果是字符则直接加
//             if (!isdigit(s[i]))
//                 res += s[i++];
//             else {
//                 int n = 0;
//                 //如果是数字则计算长度，要考虑不小于10的数
//                 while (i < s.length() && isdigit(s[i]))
//                     n = n * 10 + s[i++] - '0';
//                 //这里一般就是括号
//                 i++; // '['
//                 //直接省略括号，然后将这个代入递归操作
//                 string t = decodeString(s, i);
//                 i++; // ']'
//                 //返回的t肯定是要加多少次的
//                 while (n-- > 0)
//                     res += t;
//             }
//         }
//         //这里也是返回每一次递归所得到的字符
//         return res;
//     }
    
//     //调用
//     string decodeString(string s) {
//         int i = 0;
//         return decodeString(s, i);
//     }
// };


// class Solution {
// public:
//     string decodeString(string s) {
//         int pos = 0;
//         return helper(pos, s);
//     }
    
//     string helper(int& pos, string s) {
//         int num=0;
//         string word = "";
//         for(;pos<s.size(); pos++) {
//             char cur = s[pos];
//             //每次遇到[的时候将剩余字符传入，子问题递归
//             if(cur == '[') {
//                 string curStr = helper(++pos, s);
//                 for(;num>0;num--) word += curStr;
//             } else if (cur >= '0' && cur <='9') {
//                 num = num*10 + cur - '0';
//                 //当遇到了 ] 时则代表结束子问题的递归了
//             } else if (cur == ']') {
//                 return word;
//             } else {    // Normal characters
//                 word += cur;
//             }
//         }
//         return word;
//     }
// };