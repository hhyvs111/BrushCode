class Solution {
public:
    int countSubstrings(string s) {
        //这里的子串有很多啊，如果是规定顺序的话，要遍历n*n次。
        //可以以这个每个字符为中心，向两边扩散，如果相等则ans+1
        int ans = 0;
        int size = s.size();
        for(int i = 0 ; i < size;i++)
        {
            int left = i, right = i;
            while(left >= 0 && right < size)
            {
                if(s[left] == s[right])
                {
                    // cout<< left << endl;
                    ans++;
                    left--;
                    right++;
                }
                //如果相等则继续走，不相等直接跳出
                else
                    break;
            }
            //上面那种只判断了计数情况，还要判断偶数情况
            left = i, right = i+1;
            while(left >= 0 && right < size)
            {
                if(s[left] == s[right])
                {
                    // cout<< left << endl;
                    ans++;
                    left--;
                    right++;
                }
                //如果相等则继续走，不相等直接跳出
                else
                    break;
            }
            
        }
        return ans;
    }
};
//自己个蠢逼压根想不到这个方法啊，心累！