class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //如果是1则要前进2字符，必须要用11或者10组成。
        //从头到尾遍历，如果是1则进2位，当遇到0的时候判断是否是n-1位，是则true，否则false
        int n = bits.size();
        for(int i = 0 ; i < n;i++)
        {
            if(bits[i] == 1 && i < n)
                i++;
            else if(i == n - 1 && bits[i] == 0)
                return true;
            
        }
        return false;
    }
};