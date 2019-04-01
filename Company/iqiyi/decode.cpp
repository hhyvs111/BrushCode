#include<bits/stdc++.h>
using namespace std;
    string decodeString(const string& s,int& i)
    {
        string res;
        //这里要判括号之前的内容
        while(i < s.length() && s[i] != ']')
        {
            //判断如果不是数字是字符就将结果加入到res并自增
            if(!isdigit(s[i]))
                res += s[i++];
            else
            {
                //如果是数字则要计算其值，比如1和12是不一样的，所以要循环处理。
                int n = 0;
                while(i < s.length() && isdigit(s[i]))
                {
                    n = n*10 + (s[i++] - '0');
                }
                //跳过[，数字的左边肯定是字符j
                i++;
                //这一步很精髓，将其递归调用，如果没有其他的数字则会返回自己，如果有数字就重复处理。因为调用的是从外到内调用。
                string t = decodeString(s, i);
                //跳过]
                i++;
                while(n--)
                    res += t;
            }
        }
        return res;
    }
int main()
{
    string str;
	while(cin >> str){
        int i = 0;
        cout << decodeString(str, i);
    }
    return 0;
}

