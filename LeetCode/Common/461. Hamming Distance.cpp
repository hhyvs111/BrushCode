class Solution {
public:
    int hammingDistance(int x, int y) {
        //海明距离，计算位数不同的数
        int ans = 0;
        while(x || y)
        {
            if(x % 2  != y % 2)
                ans++;
            x /= 2;
            y /= 2;
        }
        return ans;
    }
};