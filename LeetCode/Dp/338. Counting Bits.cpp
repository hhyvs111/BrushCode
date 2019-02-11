class Solution {
public:
    vector<int> countBits(int num) {
        //计算从0到num的整数二进制中1的个数。如果一次次计算是肯定很慢的。一看就不会做。
        vector<int> ans;
        for(int i = 0 ;i <= num; i++)
        {
            int cnt = 0;
            int j = i;
            while(j)
            {
                if(j%2 == 1)
                    cnt++;
                j/=2;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

//这个方法利用了啥，动态规划？i&i-1就是
// 想一想，当一个数为2的整数幂的时候，1的个数为1，比如2（10) 和4(100)，8(1000)

// 在这之后就是前一个序列的数+1 比如 9(1001) = 1(1) + 8 (1) = 2

// 就是把一个数分解为小于它的最大2的整数幂 + x
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};